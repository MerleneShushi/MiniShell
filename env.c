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

void ft_env(char **envp)
{
  t_list  *head;
  t_list  *info;
  int     i;

  i = 0;
  while (envp[i])
  {
    info = ft_lstnew(envp[i]);
    ft_lstadd_back(&head, info);
    i++;
  }
  {
    printf("%s\n", myshell->env[i]);
    i++;
  }
}
