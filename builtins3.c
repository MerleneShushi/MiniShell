/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarrilh <dcarrilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 15:02:03 by dcarrilh          #+#    #+#             */
/*   Updated: 2023/08/22 15:02:05 by dcarrilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void ft_del_env(t_list **head, char *name)
{
  t_list  *current;
  t_env *exp_node;
  t_list  *previous;
  t_env *new_node;

  current = *head;
  previous = NULL;
  new_node = create_env_node(name);
  while (current != NULL)
  {
    exp_node = (t_env *)current->content;
    if (ft_strchr(exp_node->name, '='))
    {
      if ((ft_strncmp(exp_node->name, new_node->name, (ft_strlen(exp_node->name) -1)) == 0) && (ft_strlen(exp_node->name) - 1) == ft_strlen(new_node->name))
      {
        ft_printf("found\n");
        if (previous == NULL)
          *head = current->next;
        else
          previous->next = current->next;
        free(exp_node->name);
        free(exp_node->info);
        ft_lstdelone(current, free);
        free(new_node->name);
        free(new_node->info);
        free(new_node);
        return ;
      }
    }
    // free(exp_node->name);
    // free(exp_node->info);
    // free(exp_node);
    previous = current;
    current = current->next;
  }
  free(new_node->name);
  free(new_node->info);
  free(new_node);
}

void ft_del_exp(t_list **head, char *name)
{
  t_list  *current;
  t_env *exp_node;
  t_list  *previous;
  t_env *new_node;

  current = *head;
  previous = NULL;
  new_node = create_exp_node(name);
  while (current != NULL)
  {
    exp_node = (t_env *)current->content;
    printf("%s\n", exp_node->name);
    printf("%s\n", new_node->name);
    if (ft_strchr(exp_node->name, '='))
    {
      if ((ft_strncmp(exp_node->name, new_node->name, (ft_strlen(exp_node->name) -1)) == 0) && (ft_strlen(exp_node->name) - 1) == ft_strlen(new_node->name))
      {
        ft_printf("found\n");
        if (previous == NULL)
          *head = current->next;
        else
          previous->next = current->next;
        free(exp_node->name);
        free(exp_node->info);
        ft_lstdelone(current, free);
        free(new_node->name);
        free(new_node->info);
        free(new_node);
        return ;
      }
    }
    else if (ft_strncmp(exp_node->name, new_node->name, ft_strlen(exp_node->name)) == 0)
    {
      ft_printf("found\n");
      if (previous == NULL)
        *head = current->next;
      else
        previous->next = current->next;
      free(exp_node->name);
      free(exp_node->info);
      ft_lstdelone(current, free);
      free(new_node->name);
      free(new_node->info);
      free(new_node);
      return ;
    }
    previous = current;
    current = current->next;
  }
  free(new_node->name);
  free(new_node->info);
  free(new_node);
}

void  ft_unset(t_shell *myshell)
{
  if (myshell->ctoken == 1)
    ft_printf("/n");
  else
  {
  ft_del_exp(&myshell->myexp, myshell->token[1]);
  ft_del_env(&myshell->myenv, myshell->token[1]);
  }
}
