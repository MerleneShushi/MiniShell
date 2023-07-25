/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarrilh <dcarrilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 14:09:33 by dcarrilh          #+#    #+#             */
/*   Updated: 2023/07/18 14:09:35 by dcarrilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "libft/libft.h"
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_PATH_LENGTH 1024

typedef struct s_shell
{
  char	*minput;
  char  *pwd;
  char  *home;
  char  *path;
  char  *myecho;
  char  **token;
  int   ctoken;
}				t_shell;

int	main();
int	ft_strcmp(char *s1, char *s2);
int	ft_exit(t_shell *myshell);
int	ft_counttoken(t_shell *myshell);
void  ft_pwd(t_shell *myshell);
void  ft_cd(t_shell *myshell);
void  ft_echo(t_shell *myshell);

#endif