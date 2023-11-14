/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_not_forkable.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brolivei < brolivei@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 11:28:45 by brolivei          #+#    #+#             */
/*   Updated: 2023/09/19 12:33:54 by brolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
				IS_NOT_FORKABLE


		Esta funcao responde apenas a pergunta "E necessario criar um processo
	child para correr este comando?" - Se sim, retorna 0, se nao retorna 1.
*/

int	is_not_forkable(char *command, char *arg)
{
	if (!ft_strcmp(command, "cd") || !ft_strcmp(command, "exit") \
		|| (!ft_strcmp(command, "export") && arg) \
		|| !ft_strcmp(command, "unset"))
		return (1);
	return (0);
}

/*
				IS_BUILTIN


		Verifica apenas se os comandos sao de construcao interna.

		Retorna 1 caso o sejam.

		Retorna 0 caso nao sejam.
*/

int	is_builtin(char *command)
{
	if (!ft_strcmp(command, "exit") || !ft_strcmp(command, "pwd") \
		|| !ft_strcmp(command, "env") || !ft_strcmp(command, "echo") \
		|| !ft_strcmp(command, "unset") || !ft_strcmp(command, "export") \
		|| !ft_strcmp(command, "cd"))
		return (1);
	return (0);
}
