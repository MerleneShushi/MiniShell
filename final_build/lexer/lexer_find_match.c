/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_find_match.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brolivei < brolivei@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 14:53:59 by brolivei          #+#    #+#             */
/*   Updated: 2023/09/20 14:55:13 by brolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
				LEXER_FIND_MATCH

		A função lexer_find_match é responsavel por tratar de tokens que
	possam ser unidos e coloca-los na lista de tokens com as informações
	necessárias para que mais tarde possam ser trabalhados de acordo com
	elas.

		INPUT:

			A função recebe três parâmetros:

				match - Ponteiro para sequência de caracteres a ser
				a ser analisada.

				input - Ponteiro para sequência de caracteres que
				está a ser analisada.

				tokens - Ponteiro para lista onde os tokens são
				armazenados.

		Funcionamento:

			1º - Declaramos uma variavel inteira chamada jump.
				 Essa variavel será responsavel por reter o número
			de caracteres a percorrer no input até chegar ao match
			seguinte. Por exemplo:

					Caso match = '"' , jump ficará com a distância até
				ao próximo caractere '"'.

			2º - Declaramos a variável inteira "can_merge". A variavel
			terá o valor de zero ou um, não pode ou pode ser unido,
			correspondentemente.

			3º - Declaramos um ponteiro char para o novo token.

			4º - A variável jump, é calculada usando a função ft_strlen_sep.

			5º - can_merge é calculado definido com a função is_mergeable.
				A função, irá analisar segundo determinados parâmetros se o token
			atual poderá ou não ser unido ao próximo.

			6º - Usando a função ft_substr criamos então a nova string para
			o novo token.

			7º - Dependendo do token, usamos a já conjhecida função lexer_push_token
			para então formar o novo token e colocá-lo na lista de tokens.

		Retorno:

			Retorna NULL caso não tenha sido possivel criar token.

			Retorna o numero de caracteres para o próximo token. (jump)
*/

int	lexer_find_match(char *match, char *input, t_list **tokens)
{
	int		jump;
	int		can_merge;
	char	*token;

	jump = ft_strlen_sep(input, match);
	can_merge = is_mergeable(input, match, jump);
	token = ft_substr(input, 0, jump);
	if (!token)
		return (0);
	if (match[0] == '"')
		lexer_push_token(token, DOUBLE_QUOTES, can_merge, tokens);
	else if (match[0] == '\'')
		lexer_push_token(token, SINGLE_QUOTES, can_merge, tokens);
	else
		lexer_push_token(token, TERM, can_merge, tokens);
	return (jump);
}
