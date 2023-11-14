/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brolivei < brolivei@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 11:09:13 by brolivei          #+#    #+#             */
/*   Updated: 2023/09/19 14:33:45 by brolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	handle_error(char *msg, char *extra, int status)
{
	if (extra)
		printf("%s%s\n", msg, extra);
	else
		printf("%s\n", msg);
	ms()->exit_status = status;
	return (0);
}
