/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brolivei < brolivei@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 11:50:26 by brolivei          #+#    #+#             */
/*   Updated: 2023/09/19 14:31:20 by brolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	exec_command(char **args)
{
	ms()->exit_status = 0;
	if (!is_builtin(args[0]))
		exec_if_is_real(args[0], args);
	else if (!ft_strcmp(args[0], "exit"))
		ft_exit(args);
	else if (!strcmp(args[0], "pwd"))
		ft_pwd();
	else if (!strcmp(args[0], "env"))
		ft_myenv(args);
	else if (!ft_strcmp(args[0], "echo"))
		ft_echo(args);
	else if (!ft_strcmp(args[0], "unset"))
		ft_unset(args);
	else if (!ft_strcmp(args[0], "export"))
		ft_myexp(args);
	else if (!ft_strcmp(args[0], "cd"))
		ft_cd(args);
}
