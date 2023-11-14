/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirects.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brolivei < brolivei@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 12:47:08 by brolivei          #+#    #+#             */
/*   Updated: 2023/09/19 12:53:03 by brolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_redirection(t_token *token)
{
	if (!(token->type >= IN_1 && token->type <= OUT_2))
		return (0);
	else
		return (1);
}

void	exec_redirection(t_class type, char *file)
{
	if (type == IN_1)
		(ms()->fd_in) = open(file, O_RDONLY);
	else if (type == OUT_1
		&& !ft_strcmp(((t_token *)ms()->tokens->content)->str, ">"))
		(ms()->fd_out) = open(file, O_WRONLY | O_CREAT, 0666);
	else if (type == OUT_1)
		(ms()->fd_out) = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0666);
	else if (type == IN_2)
		(ms()->fd_in) = heredoc(file);
	else if (type == OUT_2)
		(ms()->fd_out) = open(file, O_WRONLY | O_CREAT | O_APPEND, 0666);
	if (ms()->fd_in == -1 || ms()->fd_out == -1)
	{
		printf("Minishell: %s: No such file or directory\n", file);
		ms()->exit_status = 1;
	}
}
