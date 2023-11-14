/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brolivei < brolivei@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 14:55:00 by brolivei          #+#    #+#             */
/*   Updated: 2023/09/21 15:19:38 by brolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	prompt(void)
{
	char	*lugar;
	char	*tmp;

	lugar = NULL;
	lugar = getcwd(lugar, 2000);
	tmp = ft_strjoin(lugar, "$> ");
	ms()->input = readline(tmp);
	if (!ms()->input)
	{
		free(lugar);
		free(tmp);
		clean_everything();
	}
	if (ms()->input[0] != '\0')
		add_history(ms()->input);
	free(lugar);
	free(tmp);
}
