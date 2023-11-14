/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brolivei < brolivei@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 11:48:04 by brolivei          #+#    #+#             */
/*   Updated: 2023/09/20 14:52:53 by brolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
				LEXER

		Funcao lexer: Divide o input em tokens de forma grosseira.

		A Funcao lexer recebe o input contendo todos os comandos e PIPES.

		Percorre a string atraves dos seus ifs, que a levam a funcao,
	que dependendo da especificidade do token, fazem trabalhos diferente,
	retornando sempre o tamanho do token, que sera adicionado ao i, para
	avancar no percurso do input.

		Vamos examinar os diferentes ifs:

			1: "if (input[i] == ' ')"
				Avanca os espacos em branco do input.

			2: "else if (input[i] == '|')"
				Cria o Token de PIPE e adiciona-o na lista linkada.

			3: "else if (!ft_strncmp(input[i], "<<", 2))"
				Com ft_strncmp, verifica se a partir do bite dado(input[i])
			o input é um redirect de entrada duplo, caso seja, faz um token
			com esse comando.

			4: "else if (!ft_strncmp(input[i], ">>", 2))"
				O passo 4, funciona da mesma forma que o passo 3, mas desta
			vez procurando um redirect de saida duplo. Caso seja encontrado
			é produzido um novo token deste tipo e adicionado à lista.

			5: "else if (input[i] == '<')"
				No passo 5 verificamos se o caractere que temos no input
			e um redirect de input single.
				E importante que esta verificação seja realizada depois de
			verificar os redirect duplos, pois pode causará erros se for
			de forma contraria.

			6: "else if (input[i] == '>')"
				O passo 6 é igual ao passo 5 mas para o redirect single de
			saida.

			7: "else if (input[i] == '"')"
				No passo 7, tratamos então do input relacionado com QUOTES.
				Usamos neste caso a função lexer_find_match. Ela verifica
			se o token pode ser ligado ao token adjacente à sua frente, e
			cria-lo de acordo com essa informação.
				O index para percorrer o input é avançado mais dois, de
			forma a ir para o proximo token.

			8: "else if (input[i] == '\'')"
				Este passo é feito da mesma forma do anterior mas tendo em conta
			aspas simples.

			9:
				Por ultimo temos um else, que trata de transformar em token
			todos os restantes comandos.
				Usamos novamente lexer_find_match, pois poderemos unir um
			comando a outro ou então um comando a uma string que vem depois, etc...

		Retorno:

			Retorna um ponteiro para a lista de tokens criada através do input
		dado.
*/

int	lexer_red(char *input, t_list **tokens, int i)
{
	int	x;

	x = 0;
	if (input[i] == '"')
		x += lexer_find_match("\"", &input[i + 1], tokens) + 2;
	else if (input[i] == '\'')
		x += lexer_find_match("'", &input[i + 1], tokens) + 2;
	return (x);
}

t_list	*lexer(char *input)
{
	t_list	*tokens;
	int		i;

	i = 0;
	tokens = NULL;
	while (input[i])
	{
		if (input[i] == ' ')
			i++;
		else if (input[i] == '|')
			i += lexer_push_token(ft_strdup("|"), PIPE, 0, &tokens);
		else if (!ft_strncmp(&input[i], "<<", 2))
			i += lexer_push_token(ft_strdup("<<"), IN_2, 0, &tokens);
		else if (!ft_strncmp(&input[i], ">>", 2))
			i += lexer_push_token(ft_strdup(">>"), OUT_2, 0, &tokens);
		else if (input[i] == '<')
			i += lexer_push_token(ft_strdup("<"), IN_1, 0, &tokens);
		else if (input[i] == '>')
			i += lexer_push_token(ft_strdup(">"), OUT_1, 0, &tokens);
		else if (input[i] == '\'' || input[i] == '"')
			i += lexer_red(input, &tokens, i);
		else
			i += lexer_find_match(SYMBOLS, &input[i], &tokens);
	}
	return (tokens);
}
