/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_variable.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brolivei < brolivei@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 14:47:10 by bruno             #+#    #+#             */
/*   Updated: 2023/09/19 12:25:05 by brolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
				EXPAND_VARIABLE


		A função expand_variable será responsável por substituir as
	variáveis de ambiente ou retorno do último comando a ser
	expandidas em um token, pelo seu valor.


		INPUT:

			t_token *token: Token, onde será substituido o valor da variável
		a expandir.
			t_list *envlist: A função irá buscar a informação das variáveis
		de ambiente, a esta lista.
			int exit_status: exit_status do último comando utilizado.


		Funcionamento:

			1º - Declaração das variáveis necessárias:

				char *value: Valor de substituição.

				char *key: Chave da variável a substituir.

				char *tmp: Ponteiro que apontará para a str que será
				substituida, de maneira a libertar-mos essa memória
				depois da troca.

			2º - A função entrará num loop, que usando a função ft_strnstr
			verificará se o caractere '$' está contido na str do token em
			análise, principiando uma variável a ser expandida.

			3º - key inicializado, recorrendo à função, find_key, com o
			valor da chave. Exemplo

				token->str = "O valor de $variável";

				key = "variável";

			4º - Usando a ft_strcmp, verificamos se a chave é igual a "$?".

				 Caso se verifique que sim, estamos perante a variável de
			exit_status do ultimo comando.

			5º - Caso o passo 4 não se varifique, recorremos então à função
			get_env, que irá buscar dentro de token->str o valor da variável
			a ser expandida.

			6º - tmp é apontado para token->str, de manéiras a que seja possível
			libertar essa memória depois da string substituída.

			7º - Usando a função ft_strreplace, é substituido, token->str
			por uma nova string, já com o valor ao invés do nome da variável.

			8º - Por fim, é libertada toda a memória que já não será usada.
*/

void	expand_variable(t_token *token, t_list *envlist, int exit_status)
{
	char	*value;
	char	*key;
	char	*tmp;

	while (ft_strnstr(token->str, "$", ft_strlen(token->str)))
	{
		key = find_key(token->str);
		if (!ft_strcmp(key, "$"))
			value = ft_strdup("$");
		else if (!ft_strcmp(key, "$?"))
			value = ft_itoa(exit_status);
		else
			value = get_env_exp(key, envlist);
		tmp = token->str;
		token->str = ft_strreplace(token->str, key, value);
		free(tmp);
		free(value);
		free(key);
		if (ft_strlen(token->str) == 1)
			break ;
	}
}
