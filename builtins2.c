/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builts2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarrilh <dcarrilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 11:05:07 by dcarrilh          #+#    #+#             */
/*   Updated: 2023/08/14 11:05:10 by dcarrilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void  free_env_list(t_list *head)
{
  t_list  *current;
  t_env *env_node;
  t_list  *temp;

  current = head;
  while (current != NULL)
  {
    env_node = (t_env *)current->content;
    free(env_node->name);
    free(env_node->info);
    free(env_node);
    temp = current;
    current = current->next;
    free(temp);
  }
}

void  ft_myenv(t_shell *myshell)
{
  t_list  *current;
  t_env *env_node;

  current = myshell->myenv;
  while (current != NULL)
  {
    env_node = (t_env *)current->content;
    printf("%s%s\n", env_node->name, env_node->info);
    current = current->next;
  }
  free_env_list(myshell->myenv);
}

void ft_printexp(t_shell *myshell)
{
  t_list  *current;
  t_env *exp_node;

  current = myshell->myexp;
  while (current != NULL)
  {
    exp_node = (t_env *)current->content;
    ft_printf("%s%s\n", exp_node->name, exp_node->info);
    current = current->next;
  }
  //free_env_list(myshell->myexp);
}
int ft_strcmp_exp(char *s1, char *s2, char a)
{
  int i;

  i = 0;
  while (s1[i] != a && s2[i] != a && s1[i] == s2[i] && s1[i] != '\0')
    i++;
  if (s1[i] == a || s2[i] == a)
    return (s1[i-1] - s2[i-1]);
  return (s1[i] - s2[i]);
}

void  ft_addexp(t_shell *myshell, int t)
{
  t_env *new_node;
  t_list  *current;
  t_env *current_node;

  new_node = create_exp_node(myshell->token[t]);
  current = myshell->myexp;
  while (current != NULL)
  {
    current_node = (t_env *)current->content;
    if (ft_strcmp_exp(new_node->name, current_node->name, '=') == 0)
    {
      if (ft_strlen(new_node->name) > ft_strlen(current_node->name))
        current_node->name = new_node->name;
      if (!ft_strchr(new_node->name, '='))
        break;
      if (ft_strcmp(new_node->info, current_node->info) == 0)
        break;
      else
      {
        current_node->info = new_node->info;
        break;
      }
    }
    else
      current = current->next;
  }
  if (current == NULL)
    ft_lstadd_back(&myshell->myexp, ft_lstnew(new_node));
  //free(new_node);
}
void  ft_myexp(t_shell *myshell)
{
  int t;
  
  t = 1;
  if (myshell->ctoken == 1)
    ft_printexp(myshell);
  else
  {
    while (t < myshell->ctoken)
    {
      ft_addexp(myshell, t);
      t++;
    }
    ft_sort_exp(myshell->myexp);
    ft_printexp(myshell);
  }
}