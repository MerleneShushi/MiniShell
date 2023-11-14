/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brolivei < brolivei@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 14:05:51 by brolivei          #+#    #+#             */
/*   Updated: 2023/09/04 14:42:28 by brolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*get_env(char *name)
{
	t_env	*tmp;
	t_list	*curr;

	if (name[0] == '$')
		name++;
	curr = ms()->envlist;
	while (curr)
	{
		tmp = (t_env *)curr->content;
		if (!ft_strcmp(tmp->name, name))
			return (ft_strdup(tmp->info));
		curr = curr->next;
	}
	return (ft_strdup(""));
}

void	update_envs(void)
{
	char	*tmp;

	tmp = get_env("PATH=");
	(ms()->path) = ft_split(tmp, ':');
	free(tmp);
}
