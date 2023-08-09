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

#include <readline/readline.h>
#include <readline/history.h>
#include "libft/libft.h"
#include <limits.h>
#include <sys/wait.h>

#define MAX_PATH_LENGTH 1024

extern  int  g_exit;

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

typedef struct s_env
{
  char  *name;
  char  *info;
}       t_env;

int	main();
int	ft_strcmp(char *s1, char *s2);
int	ft_exit(t_shell *myshell);
int	ft_counttoken(t_shell *myshell);
void  ft_pwd(t_shell *myshell);
void  ft_cd(t_shell *myshell);
void  ft_echo(t_shell *myshell, int a);
t_list  *ft_env(char **envp);
t_env *create_env_node(char *envp);


#endif