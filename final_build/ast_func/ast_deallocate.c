/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_deallocate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brolivei < brolivei@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 14:17:03 by brolivei          #+#    #+#             */
/*   Updated: 2023/09/06 10:32:03 by brolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
				DEALLOCATE_AST


		A funcao deallocate_ast e responsavel por libertar a memoria
	de uma estrutura de arvore sintatica t_ast.

		INPUT:

			Ponteiro para o inicio da arvore.

		FUNCIONAMENTO:

			1 - E verificado se o node existe antes de tentar aceder a ele,
		evitando crash do programa.

			2 - Se o nodulo tiver um token associado a ele, esse token
		sera destruido com recurso a funcao token_destroy.

			3 - Se a array de argumentos deste nodulo tiver preenchida,
		com recurso a funcao matrix_destroy, e tambem libertada a memoria desta matrix.

			4 - A funcao e chamada recursivamente para o ponteiro da esquerda
		e para o ponteiro da direita, fazendo assim a iteracao de toda
		a arvore abstrata.

			5 - Por fim, e libertada a memoria alocada para a estrutura
		destruido assim o nodulo e libertando a sua memoria.
*/

void	deallocate_ast(t_ast *node)
{
	if (node == NULL)
		return ;
	if (node->token != NULL)
		token_destroy((t_token *)(node->token));
	if (node->args != NULL)
		array_destroy(node->args);
	deallocate_ast(node->left);
	deallocate_ast(node->right);
	free(node);
}
