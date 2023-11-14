/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brolivei <brolivei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 11:05:07 by dcarrilh          #+#    #+#             */
/*   Updated: 2023/09/23 17:06:00 by brolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_myenv(char **args)
{
	t_list	*current;
	t_env	*env_node;

	if (matrix_size(args) > 1)
	{
		printf("env: '%s': No such file or directory", args[1]);
		ms()->exit_status = 127;
		return ;
	}
	current = ms()->envlist;
	while (current != NULL)
	{
		env_node = (t_env *)current->content;
		printf("%s%s\n", env_node->name, env_node->info);
		current = current->next;
	}
}

void	ft_printexp(void)
{
	t_list	*current;
	t_env	*exp_node;

	current = ms()->explist;
	while (current != NULL)
	{
		exp_node = (t_env *)current->content;
		ft_printf("%s%s\n", exp_node->name, exp_node->info);
		current = current->next;
	}
}

void	ft_addexp(char *arg)
{
	t_env	*new_node;
	t_list	*current;
	t_env	*current_node;

	new_node = create_exp_node(arg);
	current = ms()->explist;
	while (current != NULL)
	{
		current_node = (t_env *)current->content;
		if (ft_strcmp_exp(new_node->name, current_node->name, '=') == 0)
		{
			if (ft_addexp_red(current_node, new_node, 2) == 1)
				break ;
		}
		else
			current = current->next;
	}
	if (current == NULL)
		ft_lstadd_back(&ms()->explist, ft_lstnew(new_node));
	else
		destroy_env(new_node);
}

void	ft_addenv(char *args)
{
	t_env	*new_node;
	t_list	*current;
	t_env	*current_node;

	new_node = create_env_node(args);
	current = ms()->envlist;
	while (current != NULL)
	{
		current_node = (t_env *)current->content;
		if (ft_strcmp(new_node->name, current_node->name) == 0)
		{
			if (ft_strcmp(new_node->info, current_node->info) == 0)
				break ;
			else
				ft_addexp_red(current_node, new_node, 1);
			break ;
		}
		else
			current = current->next;
	}
	if (current == NULL && ft_strchr(new_node->name, '='))
		ft_lstadd_back(&ms()->envlist, ft_lstnew(new_node));
	else
		destroy_env(new_node);
}

void	ft_myexp(char **args)
{
	int	t;

	t = 1;
	if (matrix_size(args) == 1)
		ft_printexp();
	else if (args[t] && args[t][0] != '\0')
	{
		while (args[t])
		{
			if (ft_exp_name_valid(args[t]) == 0)
			{
				printf("bash: export: `%s': not a valid identifier\n", args[t]);
				break ;
			}
			ft_addexp(args[t]);
			ft_addenv(args[t]);
			t++;
		}
		ft_sort_exp(ms()->explist);
	}
	else
		printf("bash: export: `%s': not a valid identifier\n", args[t]);
}
