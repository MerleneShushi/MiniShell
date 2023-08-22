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

t_list  *ft_sort_exp(t_list *head)
{
  t_list  *tmp;
  void  *cont;

  tmp = head;
  while(head->next != NULL)
  {
    t_env *exp_node = (t_env *)head->content;
    t_env *exp_node2 = (t_env *)head->next->content;
    if (ft_strcmp(exp_node->name, exp_node2->name) > 0)
    {
      cont = head->content;
      head->content = head->next->content;
      head->next->content = cont;
      head = tmp;
    }
    else
      head = head->next;
  }
  head = tmp;
  return (head);
}

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
  char *temp;

  i = 0;
  j = ft_strlen(envp);
  while (envp[i] != '=' && envp[i] != '\0')
    i++;
  i++;
  if (j == i)
  {
    exp->info = ft_strdup("\"\"");
    return (exp->info);
  }
  info = ft_strdup(envp + i);
  temp = ft_strjoin("\"", info);
  exp->info = ft_strjoin(temp, "\"");
  free(info);
  free(temp);
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
  temp = head;
  head = temp;
  head = ft_sort_exp(head);
  return (head);
}




