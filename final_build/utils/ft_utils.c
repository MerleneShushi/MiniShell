/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarrilh <dcarrilh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 12:11:09 by brolivei          #+#    #+#             */
/*   Updated: 2023/09/23 14:33:20 by dcarrilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_strcmp_exp(char *s1, char *s2, char a)
{
	int	i;

	i = 0;
	while (s1[i] != a && s2[i] != a && s1[i] == s2[i] && s1[i] != '\0')
		i++;
	if ((s1[i] == a && (s2[i] == a || s2[i] == '\0'))
		|| (s2[i] == a && (s1[i] == a || s1[i] == '\0')))
		return (s1[i - 1] - s2[i - 1]);
	return (s1[i] - s2[i]);
}

int	ft_exp_name_valid(char *arg)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (arg[0] != '_' && !ft_isalpha(arg[0]))
		return (0);
	while (arg[++i])
		if (arg[i] == '=')
			j++;
	if (j > 1)
		return (0);
	i = 0;
	while (arg[++i] != '=' && arg[i])
	{
		if (!ft_isalnum(arg[i]) && arg[i] != '_')
			return (0);
	}
	return (1);
}

int	ft_echo_red(char	**args)
{
	int	n;
	int	t;

	t = 1;
	while (args[t] && (args[t][0] == '-'))
	{
		n = 0;
		while (args[t][++n])
		{
			if (args[t][n] != 'n')
				break ;
		}
		if (args[t][n] == '\0')
			t++;
		else
			break ;
	}
	return (t);
}
