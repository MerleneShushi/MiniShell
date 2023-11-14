/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brolivei < brolivei@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 14:08:25 by bruno             #+#    #+#             */
/*   Updated: 2023/09/05 11:29:05 by brolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
				EXPANDER


		A função expander trata de expandir as variáveis de expansão,
	tanto de ambiente como a variável exit_status, na lista de tokens.
		É também responsável por unir os token que possam ser unidos.

		INPUT:

			Recebe a lista de tokens a explorar.
			Recebe a lista de variáveis de ambiente, para aceder às
		variáveis a expandir.
			O valor de exit_status.

		Funcionamento:

			1º - Começamos por declarar as variáveis necessárias.

				t_list *curr: Ponteiro para iterar a lista de tokens.

				t_token *token: Ponteiro para o token a analizar.

			2º - O ponterio curr é apontado para o início da nossa lista
			de tokens.

			3º - Entramos no loop que irá iterar a lista de tokens, e
			segue-se os processo:

				1ª token é apontado para o conteodo do nódulo atual.
				2ª Se o token atual estiver definido como IN_2 (<<),
				curr é iterado dois nódulos e não apenas um. O nodulo
				seguinte ao IN_2 será o delimitador.
				3ª Caso a verificação contida em 2 não se verificar,
				passamos para um segunda verificação:
					Caso o tipo de token do nódulo atual seja DOUBLE_QUOTES
				ou um TERM existe a possibilidade de lá conter variáveis para
				serem expandidas.
					Com a função expand_variable a variavel de expanção será
				modificada para o seu valor dentro do token respetivo.
				4ª curr é iterado.
			4º - No final do loop, a função merge_tokens é chamada para
			unir os tokens que tenham essa possibilidade.
*/

void	expander(t_list *tokens, t_list *envlist, int exit_status)
{
	t_list	*curr;
	t_token	*token;

	curr = tokens;
	while (curr)
	{
		token = curr->content;
		if (token->type == IN_2)
			curr = curr->next;
		else if (token->type == DOUBLE_QUOTES || token->type == TERM)
			expand_variable(token, envlist, exit_status);
		curr = curr->next;
	}
	merge_tokens(tokens);
}
