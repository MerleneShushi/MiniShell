/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarrilh <dcarrilh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 10:16:44 by brolivei          #+#    #+#             */
/*   Updated: 2023/09/07 10:03:35 by dcarrilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_ast	*parser(t_ms *ms)
{
	t_ast	*ast;

	scanner("RESET", ms);
	ast = parse_pipeline(ms);
	return (ast);
}
