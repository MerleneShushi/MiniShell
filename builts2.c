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
