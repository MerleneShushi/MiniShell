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
int	ft_builtin(t_shell *myshell)
{
	if (ft_strcmp(myshell->token[0], "pwd") == 0)
		return (1);
	else if (ft_strcmp(myshell->token[0], "exit") == 0)
		return (1);
	else if (ft_strcmp(myshell->token[0], "cd") == 0)
		return (1);
	else if (ft_strcmp(myshell->token[0], "echo") == 0)
		return (1);
	else if (ft_strcmp(myshell->token[0], "env") == 0)
		return (1);
	else if (ft_strcmp(myshell->token[0], "export") == 0)
		return (1);
	else if (ft_strcmp(myshell->token[0], "unset") == 0)
		return (1);
	else
		return (0);
}

int	ft_exec(t_shell *myshell)
{
	int	t;
	int pid;

	t = 0;
	myshell->token = ft_split(myshell->minput, 32);
	myshell->ctoken = ft_counttoken(myshell);
	if (ft_builtin(myshell) == 1)
	{
		if (ft_strcmp(myshell->token[0], "pwd") == 0)
			ft_pwd(myshell);
		else if (ft_strncmp(myshell->token[0], "exit", 4) == 0)
			return (ft_exit(myshell));
		else if (ft_strncmp(myshell->token[0], "cd", 2) == 0)
			ft_cd(myshell);
		else if (ft_strncmp(myshell->token[0], "echo", 4) == 0)
			ft_echo(myshell, t);
		else if (ft_strcmp(myshell->token[0], "env") == 0)
			ft_myenv(myshell);
		else if (ft_strcmp(myshell->token[0], "export") == 0)
			ft_myexp(myshell);
		else if (ft_strcmp(myshell->token[0], "unset") == 0)
			ft_unset(myshell);
	}
	else 
	{
		pid = fork();
		if (pid == 0)
		{
			if (access(myshell->token[0], X_OK) == 0)
			{
						execv(myshell->token[0], myshell->token);
						perror("Erro ao executar o comando");
						return 0; // Indica erro
			}
			else
				printf("%s: Command not found\n", myshell->minput);
		}
		else if (pid > 0)
			wait(NULL);
	}
	t = 0;
	while(myshell->token[t])
	{
		free(myshell->token[t]);
		t++;
	}
	free(myshell->token);
	return (0);
}

void	ft_prompt(t_shell *myshell)
{
	char *input;
	char *tmp;
  
  input = NULL;
  input = getcwd(input, 2000);
	tmp = ft_strjoin(input, "$> ");
	myshell->minput = readline(tmp);
	if (myshell->minput[0] != '\0')
		add_history(myshell->minput);
  free(input);
	free(tmp);
}

char	**ft_paths(t_shell *myshell)
{
	int		i;
	char	**tmp;

	i = 0;
	tmp = ft_split(myshell->path, ':');
	while (tmp[i])
		i++;
	myshell->paths = malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (tmp[i])
	{
		myshell->paths[i] = ft_strdup(tmp[i]);
		free(tmp[i]);
		i++;
	}
	myshell->paths[i] = NULL;
	free(tmp);
	return (myshell->paths);
}

void	ft_initvar(t_shell *myshell, char **envp)
{
	myshell->minput = NULL;
	myshell->token = NULL;
	myshell->ctoken = 0;
	myshell->myenv = ft_env(envp);
	myshell->myexp = ft_exp(envp);
	myshell->pwd = getcwd(NULL, 2000);
	myshell->home = getenv("HOME");
	myshell->path = getenv("PATH");
	myshell->paths = ft_paths(myshell);
}

int main(int argc, char **argv, char **envp) 
{
	t_shell myshell;
	int	a;

	a = 0;
	(void)argv;
	if (argc != 1)
		ft_printf("Error: too many arguments\n");
	else
	{
		ft_initvar(&myshell, envp);
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
		free_env_list(myshell.myenv);
		free_env_list(myshell.myexp);
		while (myshell.paths[a])
		{
			free(myshell.paths[a]);
			a++;
		}
		free(myshell.paths);
	  free(myshell.minput);
		free(myshell.pwd);
  }
  return (0);
}