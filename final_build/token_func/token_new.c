/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brolivei < brolivei@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 14:19:23 by brolivei          #+#    #+#             */
/*   Updated: 2023/09/05 10:18:58 by brolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
				TOKEN_NEW


		A funcao token_new, e responsavel por criar e inicializar
	um novo bloco de memoria tipo t_token, preenchendo-o com
	os dados recebidos.

	Funcionamento:

		1 - Declara um novo ponteiro t_token.

		2 - Aloca a memoria necessaria para esse bloco usando a funcao
	ft_calloc.

		3 - Preenche os parametros da estrutura com str, class e indicacao
	se token podera ser acoplado ou nao.

	Retorno:

		Retorna NULL caso a alocacao de memoria para este novo token
	falhe.
		Retorna um ponteiro para este novo token caso seja bem sucedida.
*/

t_token	*token_new(char *str, t_class class, int can_merge)
{
	t_token	*token;

	token = ft_calloc(1, sizeof(t_token));
	if (!token)
		return (NULL);
	token->str = str;
	token->type = class;
	token->can_merge = can_merge;
	return (token);
}
