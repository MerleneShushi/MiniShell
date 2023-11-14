/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brolivei < brolivei@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 12:01:23 by dcarrilh          #+#    #+#             */
/*   Updated: 2023/09/21 15:21:48 by brolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*heredoc_expand(char *input)
{
	char	*expanded;
	char	*key;
	char	*value;

	expanded = ft_strdup(input);
	while (ft_strnstr(expanded, "$", ft_strlen(expanded)))
	{
		key = find_key(expanded);
		if (ft_strcmp(key, "$?") == 0)
			value = ft_itoa(ms()->exit_status);
		else
			value = get_env_exp(key, ms()->envlist);
		expanded = ft_strreplace(expanded, key, value);
		free(key);
		free(value);
	}
	free(input);
	return (expanded);
}

void	heredoc_reader(char *flag)
{
	int		fd;
	char	*input;

	fd = open("heredoc", O_CREAT | O_WRONLY | O_APPEND, 0666);
	while (1)
	{
		input = readline("> ");
		if (!input)
			break ;
		if (ft_strcmp(input, flag) == 0)
		{
			free(input);
			break ;
		}
		input = heredoc_expand(input);
		ft_putendl_fd(input, fd);
		free(input);
	}
	close(fd);
	clean_everything();
}

int	heredoc(char *flag)
{
	signals_heredoc();
	if (ms()->fd_in > STDIN_FILENO)
		close(ms()->fd_in);
	if (!fork())
		heredoc_reader(flag);
	signals_ignore();
	waitpid(0, NULL, 0);
	signals();
	return (open("heredoc", O_RDONLY));
}
