/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scanner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brolivei < brolivei@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 12:36:15 by brolivei          #+#    #+#             */
/*   Updated: 2023/09/19 14:31:47 by brolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
				SCANNER


		A funcao scanner tem como objetivo iterar a lista de tokens e retornar
	dependendo do comando dado, o conteodo do token, ou simplesmente iterar a
	lista.
*/

t_token	*scanner(char *str, t_ms *ms)
{
	static t_list	*curr = NULL;

	if (!ft_strcmp("READ", str) && curr)
		return (curr->content);
	else if (!ft_strcmp("RESET", str))
		curr = ms->tokens;
	else if (!ft_strcmp("NEXT", str))
		curr = curr->next;
	else if (!ft_strcmp("LOOKAHEAD", str) && curr->next)
		return (curr->next->content);
	return (NULL);
}
