/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brolivei < brolivei@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 10:33:32 by brolivei          #+#    #+#             */
/*   Updated: 2023/09/19 12:30:15 by brolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
				PARSE_COMMAND


		A função parse_command tem como objetivo criar uma parsela de novo
	comando criando o seu nódulo e as suas extensões necessária com redirect
	caso sejam encontradas.

		INPUT:

			Recebe a lista de tokens, na posição do momento.

			Recebe a estrutura ms.

		FUNCIONAMENTO:

			1º - É declarado as variáveis necessárias para a execução:

				t_ast *cmd: Estrutura do comando a parselar.
				t_list *tokens_curr: Usado para a iteração dos tokens.

			2º - tokens_curr é igualizado a tokens recebido no input.

			3º - cmd é criado, associado ao token de comando atual, com
			recurso à função ast_new, que cria e retorna um ponteiro para
			um novo nódulo ast. Este será o nódulo que representa o comando.

			4º - cmd index é igualizado ao número de comandos registados
			na estrutura ms + 1, que será o seu número de comando.

			5º - Entramos num loop, que iterará os tokens, enquanto eles
			existirem e não forem um PIPE, pois quando chegam a um PIPE
			trataremos de um novo comando.

			6º - O loop verifica se no momento o tipo de token é um redirect.
			Caso se verifique, é usado a função extend_command, para anexar
			um novo nó de redirecionamento ao nódulo de comando.

			7º - Caso contrário, o token é considerado um argumento do
			comando e anexado à matrix de argumentos do comando.

		RETORNO:

			Retorna NULL caso a alocação de memória para o novo comando
		não tenha sido possível.

			Retorna um ponteiro para o novo nódulo do comando.
*/

t_ast	*parse_command(t_ms *ms)
{
	t_ast	*cmd;

	cmd = ast_new(token_copy(scanner("READ", ms)));
	if (!cmd)
		return (NULL);
	cmd->index = ms->num_commands++;
	while (scanner("READ", ms) && scanner("READ", ms)->type != PIPE)
	{
		if ((scanner("READ", ms)->type >= IN_1
				&& scanner("READ", ms)->type <= OUT_2)
			&& !(cmd->token->type >= IN_1 && cmd->token->type <= OUT_2))
			cmd = extend_command(cmd, ms);
		else if (scanner("READ", ms)->type != OUT_1
			&& scanner("READ", ms)->type != OUT_2
			&& scanner("READ", ms)->type != IN_1
			&& scanner("READ", ms)->type != IN_2)
			cmd->args = matrix_append(cmd->args,
					ft_strdup(scanner("READ", ms)->str));
		scanner("NEXT", ms);
	}
	return (cmd);
}
