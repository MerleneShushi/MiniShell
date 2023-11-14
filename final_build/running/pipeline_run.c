/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline_run.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brolivei < brolivei@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 11:20:36 by brolivei          #+#    #+#             */
/*   Updated: 2023/09/21 10:52:37 by brolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

pid_t	execute_forkable(t_ast *command)
{
	pid_t	pid;

	signals_child();
	pid = fork();
	if (pid == 0)
	{
		if (ms()->fd_in == -1 || ms()->fd_out == -1)
			clean_everything();
		pipeline_apply(command->index);
		connect();
		exec_command(command->args);
		clean_everything();
	}
	disconnect(command->index);
	return (pid);
}

pid_t	pipeline_run(t_ast *node)
{
	pid_t	last;

	last = 0;
	if (!node)
		return (last);
	last = pipeline_run(node->left);
	last = pipeline_run(node->right);
	if (!is_redir_or_pipe(node->token))
	{
		if (is_not_forkable(node->args[0], node->args[1]))
			exec_command(node->args);
		else
			last = execute_forkable(node);
	}
	else if (is_redirection(node->token))
		exec_redirection(node->token->type, node->args[0]);
	return (last);
}
