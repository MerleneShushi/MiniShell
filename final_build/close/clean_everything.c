/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_everything.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brolivei < brolivei@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 11:46:36 by brolivei          #+#    #+#             */
/*   Updated: 2023/09/19 14:33:11 by brolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	clean_everything(void)
{
	partial_close();
	array_destroy(ms()->path);
	deallocate_env_list(ms()->envlist);
	deallocate_env_list(ms()->explist);
	free(ms()->pwd);
	exit(ms()->exit_status);
}
