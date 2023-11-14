/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brolivei < brolivei@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 11:31:26 by brolivei          #+#    #+#             */
/*   Updated: 2023/09/19 14:22:08 by brolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
				HANDLER_SIGINT


		Esta funcao ira lidar com a entrada do sinal SIGINT (CTRL-C) dada
	pelo usuario.

		O que o subject nos pede e que seja exibido um novo prompt.

		Para isso, limpamos o input dado pelo usuario usando a funcao
	rl_replace_line: Ele substituira aquilo que foi introduzido pelo
	usuario no input da readline por algo vazio. O segundo argumento dado,
	(1 ou 0), serve para dizer a funcao para apagar o historico de inputs ou
	nao. 0 = NAO 1 = SIM.

		Apos isso, usamos a funcao rl_on_new_line, que fara com que o cursor
	do usuario desca para a nova linha.

		O exit status e modificado para 130, pois e o codigo padrao de saida
	do sinal SIGINT. Isso pode ser testado no terminal pressionando CTRL-C e de
	seguida correndo o comando "echo $?".
*/

void	handler_sigint(int signum)
{
	if (signum != SIGINT)
		return ;
	rl_replace_line("", 0);
	printf("\n");
	rl_on_new_line();
	rl_redisplay();
	ms()->exit_status = 130;
}

// Para verificar depois.
void	handler_child(int signum)
{
	if (signum == SIGINT)
		ft_putstr_fd("\n", STDERR_FILENO);
	else if (signum == SIGQUIT)
		ft_putstr_fd("Quit: 3\n", STDERR_FILENO);
	(ms()->exit_status) = 128 + signum;
}

void	handler_heredoc(int signum)
{
	if (signum != SIGINT)
		return ;
	printf("\n");
	clean_everything();
}
