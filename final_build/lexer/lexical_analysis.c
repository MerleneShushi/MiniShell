/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexical_analysis.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brolivei < brolivei@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 14:41:51 by brolivei          #+#    #+#             */
/*   Updated: 2023/09/20 14:57:41 by brolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
				LEXICAL_ANALYSIS


		Funcao usada para verificar input numa primeira instancia.

		INPUT:

			Recebe um ponteiro char com a string de input.

		FUNCIONAMENTO:

			1º - São declaradas as seguintes variáveis:

				1ª - int i: Usada para iterar a string de input.
				2ª - int in_quotes: Usada para marcar casa seja detetado
				que o input está dentro de aspas.
				3ª - char quote: Usado para guardar o tipo de quote
				que temos no input.

			2º - São inicializadas as variáveis.

			3º - Com recurso à função is_spaces, é verificado se o input
			é apenas espaços. Caso se verifique que sim, é um erro e
			a função para.

			4º - De seguida entramos num loop que irá iterar a string de input.

				Dentro do loop, é verificado se existe alguma aspa. Caso
			seja encontrada, irá verificar se a mesma é fechada corretamente.


		Retorna 1 caso haja em que input seja apenas espacos.
		Retorna 2 caso haja aspas duplas ou simples que nao foram fechadas.
		Retorna 0 caso esteja o input correto.
*/

int	lexical_analysis(char	*input)
{
	int		i;
	int		in_quotes;
	char	quote;

	i = -1;
	in_quotes = 0;
	quote = '\"';
	if (is_spaces(input))
		return (1);
	while (input[++i])
	{
		if (in_quotes && input[i] == quote)
			in_quotes = 0;
		else if (!in_quotes && ft_strchr("\"\'", input[i]))
		{
			quote = input[i];
			in_quotes = 1;
		}
	}
	if (in_quotes)
	{
		printf("Error on quotes\n");
		return (2);
	}
	return (0);
}

/*
int	main()
{
	char	*str = "echo ola";
	int		x;

	x = lexical_analysis(str);

	printf("Input dado: %s\n\n", str);
	printf("\tRetorno dado pelo lexical_analysis: %d\n", x);
	return (0);
}
*/
