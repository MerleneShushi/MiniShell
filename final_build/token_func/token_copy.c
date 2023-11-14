/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_copy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brolivei < brolivei@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 10:49:31 by brolivei          #+#    #+#             */
/*   Updated: 2023/09/05 10:18:39 by brolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
				TOKEN_COPY


		A funcao token_copy e respondavel por copiar um token para um novo
	criado por ela e retorna-lo.

		INPUT:

			A funcao recebe o token a copiar.

		FUNCIONAMENTO:

			1 - Declara uma variavel estrutura tipo token, que sera a copia
			do token recebido no input.

			2 - Com recurso a token_new cria um novo token, com as informacoes
			exatamente iguais a do token recebido no input.

			3 - Verifica se a criacao correu bem.

			4 - Por fim retorn um ponteiro para esta copia do token.

		RETORNO:

			Retorna NULL caso a alocacao de memoria para esta nova copia do
		token recebido nao tenha sido conseguida.

			Retorna um ponteiro para a copia do token.
*/

t_token	*token_copy(t_token *token)
{
	t_token	*copy;

	copy = token_new(ft_strdup(token->str), token->type, token->can_merge);
	if (!copy)
		return (NULL);
	return (copy);
}
