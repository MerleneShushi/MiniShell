/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_tokens.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brolivei < brolivei@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 13:26:28 by bruno             #+#    #+#             */
/*   Updated: 2023/09/19 12:25:49 by brolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
				MERGE_TOKENS


		A função merge_tokens é responsável por unir tokens que possam
	ser unidos em um só.

		INPUT:

			Lista de tokens a analisar.

		Funcionamento:

			1º - São declaradas as variáveis necessária:

				t_list aux*: Apontador para o token que será unido a outro
				para posteriormente ser libertada a sua memória.

				t_token *next_token: Apontador para o token seguinte ao atual.

				t_token *curr_token: Apontador para o token atual.

				char *tmp: Ponteiro para a string que será unida e para
				posterior libertação de memória.

			2º - Entramos em um loop que irá iterar a lista de tokens
			até o seu final.

			3ª - curr_token é definido como o token do nódulo atual.

			4º - É verificado se estamos na presença do ultimo ou único
			token, e sendo esse o caso, já não há nada a fazer.

			5º - Se o passo anterior não se verificar, é verificado se
			o token atual está marcado como can_merge ou não. Caso se
			verifique que não é um tipo de token que possa ser unido com
			o seguinte, a iteração segue.

			6º - No caso de o token estar marcado como ser possível de
			unir com o seguinte, é começado processo de união.
				 1ª next_token é definido como o content do token seguinte.
				 2ª O ponteiro tmp aponta para a string do token atual.
				 3ª Fazendo uso da função ft_strjoin, a string do token atual
				 passa a apontar para uma nova string, que será então a união
				 da string do token atual com a string do token seguinte.
				 4ª É libertada a memória da antiga string do token atual, apontada
				 por tmp.
				 5ª É feita uma operação binaria END, entre a marcação da
				 da variável can_merge do token atual com a do seguinte,
				 de maneira a que, se o token seguinte também estiver marcado
				 com a possibilidade de união com o seguinte a ele, o token atual
				 (Que será mantido na lista, já com a nova informação), também
				 ficará com a marcação de que pode ser unido ao próximo. Isto é
				 necessário, visto que o token seguinte no momento será eliminado.
				 6ª O ponteiro aux, apontará para o lugar da memória onde está
				 contido o nodulo seguinte ao atual, o qual já unimos ao atual.
				 7ª O ponteiro next do token atual, é apontado para o após o
				 seguinte. Ou seja, o token seguinte ao atual, no passo anterior,
				 acaba de ser removido da lista.
				 8ª Usando a funçaõ ft_lstdelone, libertamos a memória do token
				 removido, com o auxilio do ponteiro aux, que está a apontar para
				 esse local na memória.
*/

void	merge_tokens(t_list *tokens)
{
	t_list	*aux;
	t_token	*next_token;
	t_token	*curr_token;
	char	*tmp;

	while (tokens)
	{
		curr_token = tokens->content;
		if (!tokens->next)
			return ;
		if (!curr_token->can_merge)
		{
			tokens = tokens->next;
			continue ;
		}
		next_token = tokens->next->content;
		tmp = curr_token->str;
		curr_token->str = ft_strjoin(curr_token->str, next_token->str);
		free(tmp);
		curr_token->can_merge &= next_token->can_merge;
		aux = tokens->next;
		tokens->next = tokens->next->next;
		ft_lstdelone(aux, (void *)token_destroy);
	}
}
