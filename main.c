/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarrilh <dcarrilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 12:32:52 by dcarrilh          #+#    #+#             */
/*   Updated: 2023/07/24 12:32:54 by dcarrilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_exit = 0;

int	ft_strcmp(char *s1, char *s2)
{
	int	a;

	a = 0;
	while (s1[a] != '\0' && s2[a] != '\0')
	{
		if (s1[a] != s2[a])
		{
			return (s1[a] - s2[a]);
		}
		a++;
	}
	return (s1[a] - s2[a]);
}

int	ft_exec(t_shell *myshell)
{
	int	t;

	t = 0;
	myshell->token = ft_split(myshell->minput, 32);
	myshell->ctoken = ft_counttoken(myshell);
	if (ft_strncmp(myshell->token[0], "exit", 4) == 0)
		return (ft_exit(myshell));
	else if (ft_strcmp(myshell->token[0], "pwd") == 0)
		ft_pwd(myshell);
	else if (ft_strncmp(myshell->token[0], "cd", 2) == 0)
		ft_cd(myshell);
	else if (ft_strncmp(myshell->token[0], "echo", 4) == 0)
		ft_echo(myshell, t);
	else
		printf("%s: Command not found\n", myshell->minput);
	return (0);
}

void	ft_prompt(t_shell *myshell)
{
	char *input;
  
  input = NULL;
  input = getcwd(input, 2000);
	input = ft_strjoin(input, "$> ");
	myshell->minput = readline(input);
	if (myshell->minput[0] != '\0')
		add_history(myshell->minput);
  free(input);
}

int main(int argc, char **argv, char **envp) 
{
	t_shell myshell;

	(void)argv;
	if (argc != 1)
		ft_printf("Error: too many arguments\n");
	else
	{
		ft_env(envp);
		myshell.pwd = getcwd(NULL, 2000);
		myshell.home = getenv("HOME");
		while(1)
		{
			ft_prompt(&myshell);
			if (myshell.minput == NULL) // Handle EOF or error condition
				break;
			if (ft_exec(&myshell) == 1)
			{
				g_exit=1;
				exit(g_exit);
			}
		free(myshell.minput);
		}
		freelol
	  free(myshell.minput);
		free(myshell.pwd);
  }
  return (0);
}