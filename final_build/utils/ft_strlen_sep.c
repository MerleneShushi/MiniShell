/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_sep.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brolivei < brolivei@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 14:57:40 by brolivei          #+#    #+#             */
/*   Updated: 2023/09/05 10:18:29 by brolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
				FT_STRLEN_SEP

		A função ft_strlen_sep calcula o numero de bites numa
	string até encontrar o caracter ou caracteres contido em
	seps.

		Funcionamento:

			1º - Entramos num loop que segue até a string do input terminar
		ou que seja encontrado um caractere correspendente a um dos
		caracteres presente em seps. Para fazer essa verificação é
		utilizada a função ft_strchr.

		Retorno:

			Retorna o numero de caracteres até chegar ao bite '\0' caso não
		encontre bite correspondente.

			Retorna o numero de caracteres até chegar ao proximo caractere
		correspondente.
*/

int	ft_strlen_sep(const char *s, char *seps)
{
	int	i;

	i = 0;
	while (s[i] && !ft_strchr(seps, s[i]))
		i++;
	return (i);
}

/*
int	main()
{
	char	*str = "\"Hola como estas?\" - Foi a pergunta.";
	int		x;

	x = ft_strlen_sep(&str[1], "\"");
	if (x == -1)
		printf("Não foi encontrado nenhum caractere coincidente com seps\n");
	else
		printf("Foi encontrado uma aspa a distancia de: %d\n", x);
}
*/
