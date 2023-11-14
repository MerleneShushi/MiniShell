/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brolivei < brolivei@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 15:02:03 by dcarrilh          #+#    #+#             */
/*   Updated: 2023/09/21 14:10:28 by brolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_del_env(t_list **head, char *name)
{
	t_list	*current;
	t_env	*exp_node;
	t_list	*previous;
	t_env	*new_node;

	current = *head;
	previous = NULL;
	new_node = create_env_node(name);
	while (current != NULL)
	{
		exp_node = (t_env *)current->content;
		if (ft_strchr(exp_node->name, '=')
			&& (ft_del_exp_red(exp_node, new_node, 0) == 1))
		{
			ft_del_exp_reduce2(&new_node, head, &current, previous);
			return ;
		}
		previous = current;
		current = current->next;
	}
	destroy_env(new_node);
}

void	ft_del_exp(t_list **head, char *name)
{
	t_list	*current;
	t_env	*exp;
	t_list	*previous;
	t_env	*new;

	current = *head;
	previous = NULL;
	new = create_exp_node(name);
	while (current != NULL)
	{
		exp = (t_env *)current->content;
		if ((ft_strchr(exp->name, '=')) && (ft_del_exp_red(exp, new, 0) == 1))
		{
			ft_del_exp_reduce2(&new, head, &current, previous);
			return ;
		}
		else if (ft_del_exp_red(exp, new, 1) == 1)
		{
			ft_del_exp_reduce2(&new, head, &current, previous);
			return ;
		}
		previous = current;
		current = current->next;
	}
	destroy_env(new);
}

void	ft_unset(char **args)
{
	int	i;

	i = 1;
	if (matrix_size(args) == 1)
		ft_printf("\n");
	while (args[i])
	{
		ft_del_exp(&ms()->explist, args[i]);
		ft_del_env(&ms()->envlist, args[i]);
		if (!ft_strcmp(args[i], "PATH"))
		{
			array_destroy(ms()->path);
			ms()->path = NULL;
		}
		i++;
	}
}
