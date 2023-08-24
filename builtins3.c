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
    printf("%s\n", name);
    if (ft_strcmp(exp_node->name, new_node->name) == 0)
    {
      ft_printf("found\n");
      if (previous == NULL)
        *head = current->next;
      else
        previous->next = current->next;
      ft_lstdelone(current, free);
      return ;
    }
    previous = current;
    current = current->next;
  }
  //printf("%s\n", exp_node->name);
}

void  ft_unset(t_shell *myshell)
{
  if (myshell->ctoken == 1)
    ft_printf("/n");
  else
  {
  ft_del_exp(&myshell->myexp, myshell->token[1]);
  //ft_del_env(myshell);
  }
}
