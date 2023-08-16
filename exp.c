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

char    *exp_name_node(t_env *exp, char *envp)
{
  int i;
  char *name;

  i = 0;
  while (envp[i] != '=' && envp[i] != '\0')
    i++;
  name = ft_calloc(sizeof(char), i + 2);
  ft_strlcpy(name, envp, i + 1);
  if (envp[i] == '=')
    name[i] = '=';
  exp->name = ft_strjoin("declare -x ", name);
  free(name);
  return (exp->name);
}

char    *exp_info_node(t_env *exp, char *envp)
{
  int i;
  int j;
  char *info;

  i = 0;
  j = ft_strlen(envp);
  while (envp[i] != '=' && envp[i] != '\0')
    i++;
  i++;
  if (j == i)
  {
    exp->info = ft_strdup(" ");
    return (exp->info);
  }
  info = ft_strdup(envp + i);
  exp->info = ft_strjoin("\"", info);
  free(info);
  return (exp->info);
}

t_env *create_exp_node(char *envp)
{
  t_env *exp;

  exp = ft_calloc(sizeof(t_env), 1);
  exp->name = exp_name_node(exp, envp);
  if (!strchr(exp->name, '='))
  {
    exp->info = ft_strdup(" ");
    return (exp);
  }
  exp->info = exp_info_node(exp, envp);
  return (exp);
}

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




