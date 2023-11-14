/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expnoexp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brolivei < brolivei@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 11:05:07 by dcarrilh          #+#    #+#             */
/*   Updated: 2023/09/19 14:44:47 by brolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_add(char	*str)
{
	ft_addexp(str);
	ft_addenv(str);
}

void	ft_expnoexp(void)
{
	t_list	*tmp;
	t_list	*tmp2;
	t_token	*tok;
	t_env	*str;

	tmp = ms()->tokens;
	while (tmp)
	{
		tmp2 = ms()->explist;
		tok = (t_token *)tmp->content;
		str = create_exp_node(tok->str);
		while (tmp2)
		{
			if (ft_strcmp_exp(str->name,
					((t_env *)tmp2->content)->name, '=') == 0)
			{
				ft_add(tok->str);
				break ;
			}
			tmp2 = tmp2->next;
		}
		destroy_env(str);
		tmp = tmp->next;
	}
	ft_sort_exp(ms()->explist);
}
