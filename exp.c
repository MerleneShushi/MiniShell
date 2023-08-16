/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarrilh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 12:19:59 by dcarrilh          #+#    #+#             */
/*   Updated: 2023/08/16 12:20:01 by dcarrilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list  *ft_exp(char **envp)
{
  t_list  *head;
  t_list  *temp;
  int     i;

  i = 0;
  head = NULL;
  ft_lstadd_back(&head, ft_lstnew(create_exp_node(envp[i])));
  temp = head;
  while (envp[++i])
  {
    temp->next = ft_lstnew(create_exp_node(envp[i]));
    temp = temp->next;
  }
  return (head);
}

t_env *create_exp_node(char *envp)
{
  int i;
  int size;
  int size2;
  t_env *exp;

  i = 0;
  exp = ft_calloc(sizeof(t_env), 1);
  if (!strchr(envp, '='))
  {
    exp->name = ft_strdup(envp);
    return (exp);
  }
  while (envp[i] != '=')
    i++;
  exp->name = ft_calloc(sizeof(char), i + 2);
  ft_strlcpy(exp->name, envp, i + 1);
  exp->name[i] = '=';
  size = i + 1;
  while (envp[++i] != '\0')
    i++;
  size2 = i - size;
  exp->info = ft_calloc(sizeof(char), size2 + 2);
  ft_strlcpy(exp->info, envp + size, size2 + 1);
  return (exp);
}
