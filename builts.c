/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builts.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarrilh <dcarrilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 12:33:48 by dcarrilh          #+#    #+#             */
/*   Updated: 2023/07/24 12:33:51 by dcarrilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int ft_counttoken(t_shell *myshell)
{
  int a;

  a = 0;
  while (myshell->token[a])
  {
    a++;
  }
  return (a);
}

int ft_exit(t_shell *myshell)
{
  int a;
  
  a = 0;
  if (myshell->ctoken > 2)
    ft_printf("%s: too many arguments\n", myshell->token[0]);
  else if (myshell->ctoken == 2)
  {
    while (myshell->token[1][a])
    {
      if (myshell->token[1][a] < 48 || myshell->token[1][a] > 57)
      {
        ft_printf("%s: %s: numeric argument required\n", myshell->token[0], myshell->token[1]);
        break;
      }
      a++;
    }
  }
  else 
    return(1);
  return (0);
}
