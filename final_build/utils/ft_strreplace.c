/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreplace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brolivei < brolivei@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 19:05:37 by brolivei          #+#    #+#             */
/*   Updated: 2023/09/05 11:37:19 by brolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
				FT_STRREPLACE


		A função ft_strreplace é responsável por substituir as ocorrências
	de uma substring contida no input old, dentro da string str, pela
	substring new.

		Funcionamento:

			1º - Declaração das variáveis necessárias:

				char *ret: Ponteiro que apontará para o início da
				nova string já com as substituições feitas.

				char *tmp: Ponteiro que deterá uma string que parte do
				início de str até à primeira ocorrência de old(Não incluida).

				char *ptr: Ponteiro que deterá uma string que parte desde
				a primeira ocorrência de old até ao final de str.

				int len: Tamanho total da string a ser criada.

			2º - Verificaçã do caso de alguma das string no input não exista,
			o que significa um erro.

			3º - No terceiro passo é calculado o tamanho total da
			string a ser criada, para que seja alocada memória para ela.

			O calculo é feito com o uso de ft_strlen.

			4º - Usando ft_calloc e a informação de len, alocamos memória
			para a nova str.

			5º - É verificado se a alocação foi bem sucedida.

			6º - Com recurso da função ft_strnstr, ptr é apontado para
			o inicio da ocorrência de old dentro da string dada str.

			7º - Com recruso à função ft_substr, tmp, é apontado
			para o início de str, até à primeira ocorrência de old.

			8ª - Com ft_strlcat, ret, é preenchido com tmp, ou seja,
			temos contruída, na nossa string que irémos retornar, a
			parte, até ao fragmento que será substituido.

			9º - Novamente com ft_strlcat, é anexado em ret, o fragmento
			de new.

			10º - Por fim, e usando novamente, ft_strlcat é anexado a ret,
			a partir do fim da ocorrência de old em ptr, o restante da string.
			Ficamos assim com a nova string, substituíndo old por new.

		Retorno:

			Retorna NULL em caso de erro de alocação de memória.

			Retorna um ponteiro para a nova string criada.
*/

char	*ft_strreplace(char *str, char *old, char *new)
{
	char	*ret;
	char	*tmp;
	char	*ptr;
	int		len;

	if (!str || !old || !new)
		return (NULL);
	len = ft_strlen(str) + ft_strlen(new) - ft_strlen(old);
	ret = ft_calloc(len + 1, sizeof(char));
	if (!ret)
		return (NULL);
	ptr = ft_strnstr(str, old, ft_strlen(str));
	if (!ptr)
		return (NULL);
	tmp = ft_substr(str, 0, ptr - str);
	ft_strlcat(ret, tmp, len + 1);
	ft_strlcat(ret, new, len + 1);
	ft_strlcat(ret, ptr + ft_strlen(old), len + 1);
	free(tmp);
	return (ret);
}
