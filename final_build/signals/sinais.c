/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sinais.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brolivei < brolivei@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 10:46:13 by brolivei          #+#    #+#             */
/*   Updated: 2023/09/19 14:21:16 by brolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// SIGINT: Sinal lancado quando precionado CTRL-C
// SIGQUIT: Sinal lancado ao pressionar CTRL-/.
// Segundo o subject nao pode fazer nada, entao lidamos com ele com o
// SIG_IGN - Signal ignore.

void	signals(void)
{
	signal(SIGINT, handler_sigint);
	signal(SIGQUIT, SIG_IGN);
}

void	signals_child(void)
{
	signal(SIGINT, handler_child);
	signal(SIGQUIT, handler_child);
}

void	signals_heredoc(void)
{
	signal(SIGINT, handler_heredoc);
	signal(SIGQUIT, SIG_IGN);
}

void	signals_ignore(void)
{
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
}
