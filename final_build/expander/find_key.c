/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brolivei < brolivei@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 15:27:13 by bruno             #+#    #+#             */
/*   Updated: 2023/09/19 12:24:12 by brolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
				FIND_KEY


		A função find_key é responsável por encontrar a chave de uma
	variável dada na string de input no formato '$nome_da_variável'.
	Ela lida também com o acontecimento de '$?'.

		Funcionamento:

			1º - É declarado um ponteiro char, que será o penteiro para
			a primeira ocorrência do caractere '$' na string dada no input.
				É declarado também um número inteiro len, que ficará com
			o tamanho da chave, para que seja formada a string de retorno.

			2º - len é colocado a 0.
				 tmp é colocado a apontar para a primeira ocorrência de '$'
			através da função ft_strnstr.

			3º - Caso, apos a ocorrência de '$' esteja o caractere '?',
			estamos perante a variavel que detém o retorno do último
			comando executado.

			4º - Caso não se verifique a condição anterior, entramos
			em um loop que intera a string tmp, até encontrar um caractere
			que não seja alfanumérico nem '_', significando o final da chave.
				 Nesse loop, é incrementado em 1, a variável len.

			5º - Por fim, é usada a função substr, para retornar um ponterio
			para um string contendo o nome da chave procurada.

		Retorno:

			Retorna um ponteiro para uma string contendo a chave procurada.

			Retorna NULL, caso não tenha sido possível alocar memória para
		essa string.
*/

char	*find_key(char *str)
{
	char	*tmp;
	int		len;

	len = 0;
	tmp = ft_strnstr(str, "$", ft_strlen(str));
	if (tmp[1] == '?')
		return (ft_strdup("$?"));
	while (ft_isalnum(tmp[len + 1])
		|| tmp[len + 1] == '_' || tmp[len + 1] == '=')
		len++;
	return (ft_substr(tmp, 0, len + 1));
}
