/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarrilh <dcarrilh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 12:33:48 by dcarrilh          #+#    #+#             */
/*   Updated: 2023/09/23 14:32:53 by dcarrilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_exit(char **args)
{
	int					t;
	unsigned long long	y;

	t = 0;
	if (args[1])
	{
		if (args[1][0] == '-')
			t++;
		y = ft_atoul(&args[1][t]);
		if (y >= 9223372036854775807)
			ft_exit_reduce(args, 0);
		while (args[1][t])
		{
			if ((args[1][t] < 48 || args[1][t] > 57))
				ft_exit_reduce(args, 0);
			t++;
		}
	}
	if (matrix_size(args) > 2)
	{
		printf("bash: exit: %s: too many arguments\n", args[1]);
		return ;
	}
	ft_exit_reduce(args, 1);
	clean_everything();
}

void	ft_pwd(void)
{
	if (getcwd(ms()->pwd, 2000) != NULL)
		printf("%s\n", ms()->pwd);
	else
		printf("Failed to get current working directory\n");
}

void	move_dir(char *path)
{
	char	*new_pwd;

	if (!ft_strcmp(path, ""))
		handle_error("Error in CD", NULL, 1);
	new_pwd = "OLDPWD=";
	new_pwd = ft_strjoin(new_pwd, ms()->pwd);
	ft_addexp(new_pwd);
	ft_addenv(new_pwd);
	free(new_pwd);
	chdir(path);
	free(ms()->pwd);
	(ms()->pwd) = getcwd(NULL, 2000);
	new_pwd = "PWD=";
	new_pwd = ft_strjoin(new_pwd, ms()->pwd);
	ft_addenv(new_pwd);
	ft_addexp(new_pwd);
	ft_sort_exp(ms()->explist);
	free(new_pwd);
	free(path);
}

void	ft_cd(char **args)
{
	struct stat	stats;

	if (matrix_size(args) > 2)
	{
		printf("minishell: cd: too many arguments");
		return ;
	}
	if ((!args[1] || !ft_strcmp(args[1], "~"))
		|| ((getenv("OLDPWD") != NULL) && !ft_strcmp(args[1], "-")))
	{
		if (!args[1] || !ft_strcmp(args[1], "~"))
			move_dir(get_env("HOME="));
		else
			move_dir(get_env("OLDPWD="));
		return ;
	}
	if (stat(args[1], &stats) != -1)
	{
		if (S_ISDIR(stats.st_mode))
			move_dir(ft_strdup(args[1]));
	}
	else
		ft_cd_reduce(args);
}

void	ft_echo(char **args)
{
	int	t;

	t = 0;
	if (matrix_size(args) == 1)
	{
		printf("\n");
		ms()->exit_status = 0;
		return ;
	}
	t = (ft_echo_red(args) - 1);
	while (args[++t])
	{
		if (args[t + 1])
			printf("%s ", args[t]);
		else
			printf("%s", args[t]);
	}
	t = (ft_echo_red(args) - 1);
	if (t == 0)
		printf("\n");
	ms()->exit_status = 0;
}
