/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   margeable.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brolivei < brolivei@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 15:24:22 by brolivei          #+#    #+#             */
/*   Updated: 2023/09/13 14:41:00 by brolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
				IS_MERGEABLE

		Com a função is_mergeable verificamos se o token que esta a ser
	criado podera ser unido ao seguinte ou não.

		Funcionamento:

			1º - No passo 1, é verificado se após o caractere match encontrado
		a str input termina. Nesse caso já não há mais nada a fazer.

			2º - Se não for encontrada diferença entre a string SYMBOLS
		(definida na biblioteca) e match, e o proximo caractere for uma
		QUOTE, então há a possibilidade de unir com o token seguinte.

			3º - No terceiro if, caso o caractere match seja uma aspa, e
		o caractere seguinte ao fecho da aspa seja um redirect ou um PIPE
		existe a possibilidade de união com o proximo token.

			Retorno:

				Retorna 1 caso haja possibilidade de união com o token
			seguinte.

				Retorna 0 caso não possa ser unido.
*/

int	is_mergeable(char *str, char *match, int jump)
{
	if (!str[jump])
		return (0);
	if (!ft_strcmp(SYMBOLS, match) && ft_strchr(QUOTES, str[jump]))
		return (1);
	if (ft_strchr(QUOTES, match[0]) && !ft_strchr(SPECIAL, str[jump + 1]))
		return (1);
	return (0);
}
