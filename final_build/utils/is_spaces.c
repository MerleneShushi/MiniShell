/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_spaces.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brolivei < brolivei@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 14:50:02 by brolivei          #+#    #+#             */
/*   Updated: 2023/09/04 15:36:29 by brolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
				IS_SPACES


		Funcao que verica se um string sao apenas espacos.

		Retorna 0 caso a string nao seja apenas espacos.
		Retorna 1 caso a string seja apenas espacos.
		Retorna 2 caso a string nao exista.
*/

int	is_spaces(const char *input)
{
	int	i;

	i = 0;
	if (!input)
		return (2);
	while (input[i])
	{
		if (input[i] != '\f' && input[i] != '\n' \
			&& input[i] != '\r' && input[i] != '\t' \
			&& input[i] != '\v' && input[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

/*
int	main()
{
	char	*str = NULL;

	if (is_spaces(str))
	{
		printf("A string nao esta de acordo com os parametros\n");
		printf("is_spaces retorna: %d\n", is_spaces(str));
	}
	else
	{
		printf("A string: <%s> esta de acordo com os parametros\n", str);
		printf("is_spaces retorna: %d\n", is_spaces(str));
	}
	return (0);
}
*/
