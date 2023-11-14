/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_redir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brolivei < brolivei@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 13:11:29 by bruno             #+#    #+#             */
/*   Updated: 2023/09/06 11:59:04 by brolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
				IS_REDIR

		Função responsável por verificar se um determinado token é um
	redirect ou não.

		Retorno:

			Retorna 1 caso o token seja um redirect.

			Retorna 0 caso o token não seja um redirect.
*/

int	is_redir(t_token *token)
{
	if (token->type >= IN_1 && token->type <= OUT_2)
		return (1);
	else
		return (0);
}
