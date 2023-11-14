/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partial_close.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brolivei < brolivei@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 15:10:35 by dcarrilh          #+#    #+#             */
/*   Updated: 2023/09/19 14:23:25 by brolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	partial_close(void)
{
	if (ms()->input)
		free(ms()->input);
	if (ms()->ast != NULL)
		deallocate_ast(ms()->ast);
	if (ms()->tokens)
		deallocate_token_list(ms()->tokens);
	if (ms()->pipes)
		array_destroy_ints(ms()->pipes);
	ms()->ast = NULL;
	ms()->tokens = NULL;
	ms()->pipes = NULL;
	ms()->num_commands = 0;
	ms()->fd_in = STDIN_FILENO;
	ms()->fd_out = STDOUT_FILENO;
}
