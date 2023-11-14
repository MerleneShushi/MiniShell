/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brolivei < brolivei@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 13:49:10 by brolivei          #+#    #+#             */
/*   Updated: 2023/09/05 15:06:00 by brolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
				MATRIX_SIZE


		A funcao matrix_size e responsavel por calcular o tamanho de uma
	array que termina em NULL.

		INPUT:

			A funcao recebe a array a calcular.

		FUNCIONAMENTO:

			1 - E declarado uma variavel int i, que sera a variavel que ira
			percorrer a matrix e tomar o valor do seu tamanho.

			2 - E verificado se a matrix tem efetivamente algum valor dentro dela.

			3 - i e inicializado a 0.

			4 - Entramos num loop que usando o i ira iterar a matrix.

		RETORNO:

			Retorna 0 caso a matrix esteja vazia.

			Retorna o valor de elementos na matrix.
*/

int	matrix_size(char **mat)
{
	int	i;

	if (!mat)
		return (0);
	i = 0;
	while (mat[i])
		i++;
	return (i);
}
