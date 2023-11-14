/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_push_token.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brolivei < brolivei@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 14:13:52 by brolivei          #+#    #+#             */
/*   Updated: 2023/09/19 14:32:49 by brolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
				LEXER_PUSH_TOKEN


		Funcao responsavel por inserir um novo token na lista de tokens.


		Funcionamento:

			1 - Declara um novo ponteiro t_token.

			2 - Usa a funcao token_new para criar e
			inicializar o novo bloco
		tipo t_token.

			3 - ft_lstadd_back e usada para colocar este novo token criado,
		na lista de token dada no input.

			4 - Por fim retorna o valor de length da string introduzida na
		lista de tokens.

		Retorno:

			1 - Retorn 0 caso nao seja possivel criar o novo nodulo.

			2 - Retorna o tamanho da string adicionada no novo token.
*/

int	lexer_push_token(char *str, t_class class,
	int can_merge, t_list **lst_tokens)
{
	t_token	*token;

	token = token_new(str, class, can_merge);
	if (!token || !str)
		return (0);
	ft_lstadd_back(lst_tokens, ft_lstnew(token));
	return (ft_strlen(str));
}
