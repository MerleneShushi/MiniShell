/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extend_pipeline.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brolivei < brolivei@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 13:49:14 by brolivei          #+#    #+#             */
/*   Updated: 2023/09/05 12:23:21 by brolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
				EXTEND_PIPELINE


		Adiciona e interliga um novo nodulo na arvore.
*/

t_ast	*extend_pipeline(t_ast *ast, t_ast *command)
{
	t_ast	*root;

	root = ast_new(token_new(ft_strdup("|"), PIPE, 0));
	if (!root)
		return (NULL);
	ast_insert(&root, ast, 1);
	ast_insert(&root, command, 0);
	return (root);
}
