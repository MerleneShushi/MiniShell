/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brolivei < brolivei@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 14:38:52 by dcarrilh          #+#    #+#             */
/*   Updated: 2023/09/19 12:39:22 by brolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_free_env(void *p)
{
	if (p)
		free(p);
	p = NULL;
}

void	destroy_env(t_env *env)
{
	ft_free_env(env->info);
	ft_free_env(env->name);
	ft_free_env(env);
}

void	deallocate_env_list(t_list *root)
{
	t_list	*curr;
	t_list	*aux;

	curr = root;
	while (curr != NULL)
	{
		aux = curr;
		curr = curr->next;
		destroy_env((t_env *)(aux->content));
		free(aux);
	}
	root = NULL;
}

t_list	*ft_env(char **envp)
{
	t_list	*head;
	t_list	*temp;
	int		i;

	i = 0;
	head = NULL;
	ft_lstadd_back(&head, ft_lstnew(create_env_node(envp[i])));
	temp = head;
	while (envp[++i])
	{
		temp->next = ft_lstnew(create_env_node(envp[i]));
		temp = temp->next;
	}
	return (head);
}

t_env	*create_env_node(char *envp)
{
	int		i;
	int		size;
	int		size2;
	t_env	*env;

	i = 0;
	env = ft_calloc(sizeof(t_env), 1);
	if (!strchr(envp, '='))
	{
		env->name = ft_strdup(envp);
		return (env);
	}
	while (envp[i] != '=')
		i++;
	env->name = ft_calloc(sizeof(char), i + 2);
	ft_strlcpy(env->name, envp, i + 1);
	env->name[i] = '=';
	size = i + 1;
	while (envp[i] != '\0')
		i++;
	size2 = i - size;
	env->info = ft_calloc(sizeof(char), size2 + 2);
	ft_strlcpy(env->info, envp + size, size2 + 1);
	return (env);
}
