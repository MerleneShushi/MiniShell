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
  char  **paths;
  char  *myecho;
  char  **token;
  int   ctoken;
  t_list  *myenv;
  t_list *myexp;
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
t_list  *ft_exp(char **envp);
t_env *create_env_node(char *envp);
t_env *create_exp_node(char *envp);
void  freeenv(t_list *env);
void  ft_myenv(t_shell *myshell);
void  free_env_list(t_list *head);
void  ft_myexp(t_shell *myshell);
t_list  *ft_sort_exp(t_list *head);
void  ft_unset(t_shell *myshell);




#endif