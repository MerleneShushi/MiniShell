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
    return (ft_printf("%s: too many arguments\n", myshell->token[0]));
  else if (myshell->ctoken == 2)
  {
    while (myshell->token[1][a])
    {
      if (myshell->token[1][a] < 48 || myshell->token[1][a] > 57)
      {
        return (ft_printf("%s: %s: numeric argument required\n", myshell->token[0], myshell->token[1]));
        break;
      }
      a++;
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

void  ft_echo(t_shell *myshell)
{
  int a;
  
  //myshell->myecho = ft_echo(myshell, myshell->minput + 5);
  if (myshell->ctoken  == 1)
    printf("\n");
  else if (ft_strcmp(myshell->token[1], "-n") == 0)
  {
    a = 1;
    while (myshell->token[++a])
    {
      if (myshell->token[a + 1])
        ft_printf("%s ", myshell->token[a]);
      else
        ft_printf("%s", myshell->token[a]);
    }
  }
  else
  {
    a = 0;
    while (myshell->token[++a])
    {
      if (myshell->token[a + 1])
        ft_printf("%s ", myshell->token[a]);
      else
        ft_printf("%s\n", myshell->token[a]);
    }
  }
  //free(myshell->myecho);
}
