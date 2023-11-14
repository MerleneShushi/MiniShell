/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_append.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brolivei < brolivei@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 13:45:56 by brolivei          #+#    #+#             */
/*   Updated: 2023/09/05 15:04:56 by brolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
				MATRIX_APPEND


		A funcao matrix_append, tem como objetivo, colocar um elemento no
	fim de uma matrix dada.

		INPUT:

			A funcao recebe um duplo ponteiro para uma matrix, onde sera
		adicionado o novo elemente.
			Recebe tambem uma string str, que sera o novo elemento a adicionar.

		FUNCIONAMENTO:

			1 - Declaracao de variaveis necessarias:

				char **res: Nova matrix com o novo elemento.
				size_t i: Variavel para iterar a lista.

			2 - E inicializado o i a -1.

			3 - E alocada a memoria necessaria para contruir a nova matrix,
			recorrendo a funcao matrix size, para sabermos o numero de blocos
			a alocar + 2, um para o novo elemento e outro para manter a array
			com NULL no seu final.

			4 - E verificado se a alocacao correu conforme.

			5 - E iniciado um loop que ira iterar a array do input, e, a medida
			que vai iterando, vai copiando o seu conteudo para a nova martix, res.
				Neste caso, recorremos a ft_strdup para fazer a copia para a
			nova matrix.

			6 - Apos essa copia, e acoplado a nova matrix a str dada no input.

			7 - Por fim, recorrendo a funcao matrix_destroy e libertada a
			memoria da matrix dada no input.

		RETORNO:

			Retorna NULL caso a alocacao de memoria para a nova matrix nao
		tenha sido possivel.

			Retorna um ponteiro para a nova matrix com o novo elemento anexado.
*/

char	**matrix_append(char **m1, char *str)
{
	char	**res;
	size_t	i;

	i = -1;
	res = ft_calloc(matrix_size(m1) + 2, sizeof(char *));
	if (!res)
		return (NULL);
	while (m1[++i])
		res[i] = ft_strdup(m1[i]);
	res[i] = str;
	array_destroy(m1);
	return (res);
}
