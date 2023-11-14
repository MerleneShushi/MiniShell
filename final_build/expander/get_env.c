/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brolivei < brolivei@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 18:37:07 by brolivei          #+#    #+#             */
/*   Updated: 2023/09/19 12:22:52 by brolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
				GET_ENV


		A função get_env, é responsavél por descobrir o valor
	de uma variável de ambiente correspondente à key dada no
	seu input.

		Funcionamento:

			1º - É declarado uma estrutura de variável de ambiente tmp,
			que será usada para analisar cada variável de ambiente à
			medida que vamos iterando a lista das mesmas.
				É declarado também uma variável t_list, para iterar a lista
			de variável de ambiente.

			2º - É verificado se o primeiro caractere da string key é '$'.
				 Caso se verifique esse facto, o ponteiro key andará um
			bite em frente, de maneira a apontar para o inicio do nome
			da variável.

			3º - curr passa a apontar para o inicio da lista de variáveis
			de ambiente.

			4º - De seguida entramos num loop que irá iterar a lista das
			variáveis:

				1: tmp aponta para a variável do momento.

				2: É comparado com recurso à ft_strcmp o valor da chave
				do nodulo atual com o valor da chave de input.

				3: Caso a comparação indique que estamos perante a variável
				procurada, é retornado o valor dessa variável com recurso
				à função ft_strdup.

		Retorno:

			Retorna um ponterio char, que contem o valor da variável
		correspondente à string do input.

			Retorna um ponteiro para uma string vazia, caso não seja
		encontrado nenhuma variável de ambiente correspondente à chave
		dada.
*/

char	*get_env_exp(char *key, t_list *envlist)
{
	t_env	*tmp;
	t_list	*curr;

	if (key[0] == '$')
		key++;
	key = ft_strjoin(key, "=");
	curr = envlist;
	while (curr)
	{
		tmp = (t_env *)curr->content;
		if (!ft_strcmp(tmp->name, key))
		{
			free(key);
			return (ft_strdup(tmp->info));
		}
		curr = curr->next;
	}
	free(key);
	return (ft_strdup(""));
}
