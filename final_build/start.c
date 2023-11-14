/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brolivei < brolivei@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 14:52:12 by brolivei          #+#    #+#             */
/*   Updated: 2023/09/21 15:21:29 by brolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
/*
void	print_tokens(t_list *tokens)
{
	t_list	*curr;
	t_token	*token;

	curr = tokens;
	while (curr)
	{
		token = (t_token *)curr->content;
		printf("Token arg: %s\n", token->str);
		printf("Token can_merge: %d\n", token->can_merge);
		printf("Token type: %u\n\n\n", token->type);
		curr = curr->next;
	}
}
*/
/*
void	print_ast(t_ast *node)
{
	if (node == NULL)
		return ;
	if (node->token != NULL)
		printf("Token: %s\n", node->token->str);
	if (node->args != NULL)
	{
		for (int i = 0; node->args[i] != NULL; i++)
			printf("Arg %d: %s\n", i, node->args[i]);
	}
	print_ast(node->left);
	print_ast(node->right);
}
*/

t_list	*del_node(t_list **tmp)
{
	ms()->tokens = (*tmp)->next;
	ft_lstdelone(*tmp, (void *)(token_destroy));
	*tmp = ms()->tokens;
	return (*tmp);
}

int	is_assignment(void)
{
	t_list	*tmp;
	t_token	*tok;

	tmp = ms()->tokens;
	while (tmp)
	{
		if (!ft_strchr(((t_token *)tmp->content)->str, '='))
		{
			tmp = ms()->tokens;
			tok = (t_token *)tmp->content;
			while (tmp && ft_strchr(tok->str, '='))
			{
				del_node(&tmp);
				tok = (t_token *)tmp->content;
			}
			deallocate_ast(ms()->ast);
			ms()->num_commands = 0;
			ms()->ast = parser(ms());
			return (1);
		}
		else if (*((t_token *)tmp->content)->str == '=')
			return (printf("Assignment Error\n"));
		tmp = tmp->next;
	}
	return (0);
}

void	compute(void)
{
	if (lexical_analysis(ms()->input))
		return ;
	ms()->tokens = lexer(ms()->input);
	if (!token_analysis(ms()->tokens))
		return ;
	expander(ms()->tokens, ms()->envlist, ms()->exit_status);
	ms()->ast = parser(ms());
	if (!is_assignment())
	{
		ft_expnoexp();
		return ;
	}
	run(ms()->ast);
}

void	start(void)
{
	while (1)
	{
		prompt();
		compute();
		partial_close();
		unlink("heredoc");
	}
	rl_clear_history();
}
