/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_destroy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brolivei < brolivei@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 14:13:47 by bruno             #+#    #+#             */
/*   Updated: 2023/09/05 10:18:50 by brolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
				TOKEN_DESTROY


		A função token_destroy é responsavel por libertar a memória do
	token dado no input.

		Funcionamento:

			1º - É verificado se o token existe.

			2º - Usando a função free, é libertada a memória da string do
			token e também a memória do token.
*/

void	token_destroy(t_token *token)
{
	if (!token)
		return ;
	free(token->str);
	free(token);
}
