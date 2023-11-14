/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_pipeline.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brolivei < brolivei@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 10:30:42 by brolivei          #+#    #+#             */
/*   Updated: 2023/09/05 12:33:26 by brolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_ast	*parse_pipeline(t_ms *ms)
{
	t_ast	*ast;
	t_ast	*command;

	command = NULL;
	ast = parse_command(ms);
	if (!ast)
		return (NULL);
	while (scanner("READ", ms) && scanner("READ", ms)->type == PIPE)
	{
		scanner("NEXT", ms);
		command = parse_command(ms);
		ast = extend_pipeline(ast, command);
	}
	return (ast);
}
