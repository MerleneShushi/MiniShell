/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reduce.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brolivei < brolivei@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:52:49 by brolivei          #+#    #+#             */
/*   Updated: 2023/09/20 14:16:58 by brolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_exit_reduce(char **args, int control)
{
	long long	x;

	if (control == 0)
	{
		printf("%s: %s: numeric argument required\n", args[0], args[1]);
		ms()->exit_status = 2;
		clean_everything();
	}
	else if (args[1])
	{
		x = ft_atol(args[1]);
		if (x >= 0)
			ms()->exit_status = x % 256;
		else
			ms()->exit_status = 256 + (x % 256);
	}
}

void	ft_cd_reduce(char **args)
{
	printf("Minishell: cd: %s: No such file or directory\n", args[1]);
	ms()->exit_status = 127;
}

int	ft_del_exp_red(t_env *exp_node, t_env *new_node, int x)
{
	if (x == 0)
	{
		if ((ft_strncmp(exp_node->name, new_node->name,
					(ft_strlen(exp_node->name) - 1)) == 0)
			&& (ft_strlen(exp_node->name) - 1) == ft_strlen(new_node->name))
			return (1);
		else
			return (0);
	}
	if (x == 1)
	{
		if ((ft_strncmp(exp_node->name, new_node->name,
					ft_strlen(exp_node->name)) == 0)
			&& (ft_strlen(exp_node->name)) == ft_strlen(new_node->name))
			return (1);
		else
			return (0);
	}
	return (0);
}

void	ft_del_exp_reduce2(t_env **new_node, t_list **head, t_list **current,
						t_list *previous)
{
	if (previous == NULL)
		*head = (*current)->next;
	else
		previous->next = (*current)->next;
	ft_lstdelone(*current, (void *)destroy_env);
	destroy_env(*new_node);
}

int	ft_addexp_red(t_env *curr, t_env *new_node, int x)
{
	if (x == 0)
	{
		free(curr->name);
		curr->name = ft_strdup(new_node->name);
	}
	if (x == 1)
	{
		free(curr->info);
		curr->info = ft_strdup(new_node->info);
	}
	if (x == 2)
	{
		if (ft_strlen(new_node->name) > ft_strlen(curr->name))
			ft_addexp_red(curr, new_node, 0);
		if ((!ft_strchr(new_node->name, '='))
			|| (ft_strcmp(new_node->info, curr->info) == 0))
			return (1);
		else
		{
			ft_addexp_red(curr, new_node, 1);
			return (1);
		}
	}
	return (0);
}
