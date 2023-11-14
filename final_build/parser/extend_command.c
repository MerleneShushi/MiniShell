/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extend_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brolivei < brolivei@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 12:46:08 by brolivei          #+#    #+#             */
/*   Updated: 2023/09/19 12:33:04 by brolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
				EXTEND_COMMAND


		A funcao extend_command e chamada quado e encontrado um token
	tipo redirect para ser adicionado na arvore sintatica abstrata.

		INPUT:

			A funcao recebe um ponteiro para uma estrutura t_ast que sera
		a linha de comando que está a ser criada.
			Recebe também um ponteiro para a lista de tokens, na posição
		que está a ser a analisada.

		FUNCIONAMENTO:

			1º - E declarado duas variaveis necessarias ao processo:

				t_ast *redir: Nodulo da arvore que ira conter o redirect.
				t_list *curr: Usado para aceder ao token seguinte.

			2º - redir e criado com recurso à função ast_new. É criado com
			o token de redirect atual, que espoletou o inicío da função.

			3º - curr é iterado um nódulo para a frente, de forma a ficar
			a apontar para o nódulo dos tokens que contém a informação com
			os argumentos do redirect.

			4º - O ponteiro args do nódulo do redirect é apontado para uma
			string que contém os argumentos do nódulo token atual, que é
			o argumento para o redirect.

			5º - O ponteiro left é apontado para o mesmo left do command.

			6º - O pontéiro left de command é apontado para redir.

		RETORNO:

			Retorna NULL caso não tenha sido possível alocar memória para
		redir.

			Retorna command, já com as alterações feitas referente ao
		redirect.
*/

t_ast	*extend_command(t_ast *command, t_ms *ms)
{
	t_ast	*redir;

	redir = ast_new(token_copy(scanner("READ", ms)));
	if (!redir)
		return (NULL);
	scanner("NEXT", ms);
	redir->args = matrix_append(redir->args,
			ft_strdup(scanner("READ", ms)->str));
	redir->left = command->left;
	command->left = redir;
	return (command);
}
