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
  int t;

  t = 0;
  while (myshell->token[t])
  {
    t++;
  }
  return (t);
}

int ft_exit(t_shell *myshell)
{
  int t;
  
  t = 0;
  if (myshell->ctoken > 2)
    return (ft_printf("%s: too many arguments\n", myshell->token[0]));
  else if (myshell->ctoken == 2)
  {
    while (myshell->token[1][t])
    {
      if (myshell->token[1][t] < 48 || myshell->token[1][t] > 57)
      {
        return (ft_printf("%s: %s: numeric argument required\n", myshell->token[0], myshell->token[1]));
        break;
      }
      t++;
    }
  }
  return(1);
}

void  ft_pwd(t_shell *myshell)
{
  
  if (getcwd(myshell->pwd, 2000) != NULL)
		printf("%s\n", myshell->pwd);
	else
		printf("Failed to get current working directory\n");
}

void  ft_cd(t_shell *myshell)
{
  //printf("%d\n", myshell->ctoken);
  if (!myshell->token[1])
	{
		if (myshell->home != NULL)
			chdir(myshell->home);
		else
			printf("Home directory not found\n");
	}
	else
  {  // Extract the path from the input
    myshell->path = myshell->token[1];
		if (chdir(myshell->path) != 0) 
        printf("Failed to change directory\n");
	}
}

void  ft_echo(t_shell *myshell, int t)
{
  if (myshell->ctoken  == 1)
    printf("\n");
  else if (ft_strcmp(myshell->token[1], "-n") == 0)
  {
    t = 1;
    while (myshell->token[++t])
    {
      if (myshell->token[t + 1])
        ft_printf("%s ", myshell->token[t]);
      else
        ft_printf("%s", myshell->token[t]);
    }
  }
  else
  {
    while (myshell->token[++t])
    {
      if (myshell->token[t + 1])
        ft_printf("%s ", myshell->token[t]);
      else
        ft_printf("%s\n", myshell->token[t]);
    }
  }
}
