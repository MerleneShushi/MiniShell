/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes_born.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brolivei < brolivei@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 10:37:45 by brolivei          #+#    #+#             */
/*   Updated: 2023/09/19 14:42:54 by brolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
				PIPELINE_CREATE


		A funcao pipeline_create e responsavel por criar a array de pipes.

		FUNCIONAMENTO:

			1 - E declarado um int i que servira para controlar o loop na
		criacao dos PIPES, para criar o numero certo deles.

			2 - E alocada a memoria necessaria na ARRAY de ints, que sera
		as pontas dos pipes.
				E alocado num_commands blocos, para termos um bloco no final
		com NULL, de maneira a sabermos o final da ARRAY.

			3 - Sao criados os PIPES consoante o num_commands - 1.

				Os pipes sao criados usando a funcao PIPE.

*/

void	pipeline_create(void)
{
	int	i;

	i = 0;
	(ms()->pipes) = ft_calloc(ms()->num_commands, sizeof(int *));
	if (!ms()->pipes)
		return ;
	while (i < ms()->num_commands - 1)
	{
		(ms()->pipes[i]) = ft_calloc(2, sizeof(int));
		pipe(ms()->pipes[i]);
		i++;
	}
}

int	is_last_command(int command_index)
{
	if (command_index == ms()->num_commands - 1)
		return (1);
	else
		return (0);
}

void	pipeline_apply(int command_index)
{
	if (ms()->num_commands < 2)
		return ;
	if (ms()->fd_in == STDIN_FILENO)
	{
		if (command_index != 0)
			ms()->fd_in = ms()->pipes[command_index - 1][0];
	}
	if (ms()->fd_out == STDOUT_FILENO)
		if (!is_last_command(command_index))
			ms()->fd_out = ms()->pipes[command_index][1];
}
