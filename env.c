/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarrilh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 14:38:52 by dcarrilh          #+#    #+#             */
/*   Updated: 2023/07/26 14:38:53 by dcarrilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


t_list  *ft_env(char **envp)
{
  t_list  *head;
  t_list  *temp;
  int     i;

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

t_env *create_env_node(char *envp)
{
  int i;
  int size;
  int size2;
  t_env *env;

  i = 0;
  env = ft_calloc(sizeof(t_env), 1);
  while (envp[i] != '=')
    i++;
  i++;
  size = i;
  env->name = ft_calloc(sizeof(char), size + 1);
  ft_strlcpy(env->name, envp, size + 1);
  env->name[size] = '\0';
  while (envp[++i] != '\0')
    i++;
  size2 = i - size;
  env->info = ft_calloc(sizeof(char), size2 + 1);
  ft_strlcpy(env->info, envp + size, size2 + 1);
  env->info[size2] = '\0';
  return (env);
}

void  freeenv(t_list *env)
{
  t_list *temp;

  while (env)
  {
    temp = env->next;
    free(env->content);
    free(env);
    env = temp;
  }
}