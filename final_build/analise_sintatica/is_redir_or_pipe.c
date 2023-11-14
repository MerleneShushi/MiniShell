/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_redir_or_pipe.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brolivei < brolivei@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 11:49:22 by bruno             #+#    #+#             */
/*   Updated: 2023/09/18 14:45:07 by brolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
				IS_REDIR_OR_PIPE

		A função is_redir_or_pipe analisa o tipo de token que recebe no
	input.

		Retorno:

			Retorn 1 caso o token esteja entre o tipo Input1 e PIPE.

			Retorna 0 caso contrário.
*/

int	is_redir_or_pipe(t_token *token)
{
	if (token->type >= IN_1 && token->type <= PIPE)
		return (1);
	else
		return (0);
}

int	is_pipe(t_token *token)
{
	if (token->type == PIPE)
		return (1);
	else
		return (0);
}
