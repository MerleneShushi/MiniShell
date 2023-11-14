/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brolivei < brolivei@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 11:02:58 by brolivei          #+#    #+#             */
/*   Updated: 2023/09/05 14:58:02 by brolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
				AST_NEW


		A funcao ast_new e respondavel por cria um novo bloco tipo
	arvore sintatica abstrata.

		INPUT:

			A funcao recebe o token a associar a esse bloco ast.

		FUNCIONAMENTO:

			1 - Declaracao de um ponteiro para o nodulo ast a criar.

			2 - De seguida e alocada memoria nesse espaco para o bloco.

			3 - E verificado se a alocacao correu com conformidade.

			4 - De seguida, o ponterio token da estrutura t_ast criada,
			e apontado para o token do input, para associa-lo a ele.

			5 - E alocada memoria para um ponteiro na array args da estrutura
			t_ast, para posterior preenchimento, se for o caso.

		Retorno:

			Retorna NULL caso ft_calloc nao consiga alocar memoria para o bloco

			Retorna um pontero para o novo nodulo ast.
*/

t_ast	*ast_new(t_token *token)
{
	t_ast	*node;

	node = ft_calloc(1, sizeof(t_ast));
	if (!node)
		return (NULL);
	node->token = token;
	node->args = ft_calloc(1, sizeof(char *));
	return (node);
}
