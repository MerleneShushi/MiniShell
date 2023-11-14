/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brolivei < brolivei@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 12:02:16 by brolivei          #+#    #+#             */
/*   Updated: 2023/09/19 12:35:03 by brolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	connect(void)
{
	if (ms()->fd_in >= STDIN_FILENO)
		dup2(ms()->fd_in, STDIN_FILENO);
	if (ms()->fd_out >= STDOUT_FILENO)
		dup2(ms()->fd_out, STDOUT_FILENO);
}

void	disconnect(int command_index)
{
	if (ms()->fd_in > STDIN_FILENO)
		close(ms()->fd_in);
	if (ms()->fd_out > STDOUT_FILENO)
		close(ms()->fd_out);
	if (command_index > 0)
		close(ms()->pipes[command_index - 1][0]);
	if (!is_last_command(command_index))
		close(ms()->pipes[command_index][1]);
	ms()->fd_in = STDIN_FILENO;
	ms()->fd_out = STDOUT_FILENO;
}
