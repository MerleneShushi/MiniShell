/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deallocate_token_list.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brolivei < brolivei@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 10:36:24 by brolivei          #+#    #+#             */
/*   Updated: 2023/09/06 10:36:46 by brolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	deallocate_token_list(t_list *root)
{
	t_list	*curr;
	t_list	*aux;

	curr = root;
	while (curr != NULL)
	{
		aux = curr;
		curr = curr->next;
		token_destroy((t_token *)(aux->content));
		free(aux);
	}
	root = NULL;
}
