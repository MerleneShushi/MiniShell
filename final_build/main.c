/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brolivei < brolivei@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 12:06:52 by brolivei          #+#    #+#             */
/*   Updated: 2023/09/19 14:36:36 by brolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	initialize_ms(char	**envp)
{
	ft_bzero(ms(), sizeof(t_ms));
	(ms()->envlist) = ft_env(envp);
	(ms()->explist) = ft_exp(envp);
	ms()->env_matrix = envp;
	update_envs();
	ms()->exit_status = 0;
	(ms()->pwd) = getcwd(NULL, 2000);
	ms()->fd_in = STDIN_FILENO;
	ms()->fd_out = STDOUT_FILENO;
	return ;
}

int	main(int argc, char **argv, char **envp)
{
	(void)argv;
	if (argc != 1)
		return (printf("ERROR: Too many args\n"));
	initialize_ms(envp);
	signals();
	start();
	return (0);
}
