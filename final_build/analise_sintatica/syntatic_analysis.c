/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntatic_analysis.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brolivei < brolivei@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 11:28:35 by bruno             #+#    #+#             */
/*   Updated: 2023/09/20 12:52:53 by brolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

	// 			SYNTATIC_ANALYSIS

	// 	A função syntatic_analysis é responsavél por analisar a sintax
	// do comando inserido através dos tokens já separados. Ela detetará erros
	// relacionados com mal formações na ordem dos comandos inseridos e também
	// erros relacionados com balanço entre números de PIPES e comandos.

	// 	Funcionamento:

	// 		1º - Declaração de variáveis:

	// 			t_token	*next - Variável responsável por conter o token
	// 						seguinte ao atual.

	// 			t_token	*atual - Variável que aponta para o token atual.

	// 			t_list	*curr - Ponteiro usado para iterar a lista de tokens.

	// 			int	num_pipes - Armazena o número de tokens tipo PIPE.

	// 			int num_commands - Armazena o número de comandos.

	// 		2º - Definição das variáveis:

	// 			num_pipes é igualado a 0.

	// 			num_commands é igualado a 1.
	//			(Para chegar a este passo tem pelo menos um comando)

	// 			curr aponta para a raiz da lista de tokens.

	// 		3º - No terceiro passo e primeira condição a verificar,
	//			a função verifica se o primeiro
	// 		token é do tipo PIPE ou um redirect, o que causa
	//		logo à partida um erro de sintax.

	// 		4º - No quarto passo a função entra num loop que
	//			irá iterar toda a lista de tokens.

	// 		Nesse loop é feito o seguinte enquanto
	//		curr não for NULL, ou seja, enquanto não
	// 	atingir o final da lista:

	// 			1 - A variável atual aponta para o token do contect
				//atual a ser analisado.

	// 			2 - Se curr->next existir, a variável next fica a
				//apontar para o token seguinte,
	// 			caso contrario aponta para NULL.

	// 			3 - Se o token atual for um redirect e
				//o next não existir ou for outro redirect
	// 			ou um PIPE, é também um erro de sintax.

	// 			4 - Se o token atual for um PIPE é
				//incrementado 1 na variável num_pipes e se
	// 			next existir e não for um redirect ou um PIPE é
				//incrementado 1 na variável
	// 			num_commands.

	// 		5º - Após o loop percorrer todos os tokens e se tudo
			//estiver em ordem lexical, é
	// 		verificado se o número de PIPES é maior ou
			//igual ao número de comandos, o que
	// 		indica um erro.

	// 	Retorno:

	// 		Retorna 0 se encontrar algum erro na sintax.

	// 		Retorna 1 caso tudo esteja correto.

void	token_analysis_red(t_token *next)
{
	if (!next)
		printf("bash: syntax error near unexpected token `newline'\n");
	else
		printf("bash: syntax error near unexpected token `%s'\n", next->str);
}

void	token_analysis_red2(t_list *curr, t_token **next)
{
	if (curr->next)
		*next = curr->next->content;
	else
		*next = NULL;
}

void	token_analysis_red3(int *num_pipes, int *num_commands, t_token *next)
{
	*num_pipes += 1;
	if (next && !is_redir_or_pipe(next))
		*num_commands += 1;
}

int	token_analysis(t_list *tokens)
{
	t_token	*next;
	t_token	*atual;
	t_list	*curr;
	int		num_pipes;
	int		num_commands;

	num_pipes = 0;
	num_commands = 1;
	curr = tokens;
	if (is_pipe(curr->content))
		return (printf("bash: syntax error near unexpected token `|'\n") * 0);
	while (curr)
	{
		atual = curr->content;
		token_analysis_red2(curr, &next);
		if (is_redir(atual) && (!next || is_redir_or_pipe(next)))
			return (token_analysis_red(next), 0);
		if (atual->type == PIPE)
			token_analysis_red3(&num_pipes, &num_commands, next);
		curr = curr->next;
	}
	if (num_pipes >= num_commands)
		return (printf("Error on number os PIPES and COMMANDS\n") * 0);
	return (1);
}
