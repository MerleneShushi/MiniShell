# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brolivei < brolivei@student.42porto.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/04 12:01:17 by brolivei          #+#    #+#              #
#    Updated: 2023/09/20 15:18:43 by brolivei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = cc
CCFLAGS = -Wall -Wextra -Werror -g #-fsanitize=address

MINISHELL = minishell

SRCS_MINISHELL = main.c\
				 global_func.c start.c\
				 prompt/prompt.c\
				 scan/scanner.c\
				 matrix/matrix_append.c matrix/matrix_size.c matrix/matrix_destroy.c\
				 ast_func/ast_deallocate.c ast_func/ast_insert.c ast_func/ast_new.c\
				 envs/env.c envs/env_2.c\
				 lexer/lexical_analysis.c lexer/lexer.c lexer/lexer_push_token.c lexer/lexer_find_match.c lexer/margeable.c\
				 analise_sintatica/is_redir_or_pipe.c analise_sintatica/is_redir.c analise_sintatica/syntatic_analysis.c\
				 parser/extend_command.c parser/extend_pipeline.c parser/parse_command.c parser/parse_pipeline.c parser/parser.c\
				 expander/expand_variable.c expander/expander.c expander/find_key.c expander/get_env.c expander/merge_tokens.c\
				 token_func/token_copy.c token_func/token_destroy.c token_func/token_new.c\
				 token_func/deallocate_token_list.c\
				 utils/is_spaces.c utils/ft_strlen_sep.c utils/ft_strreplace.c\
				 utils/error.c utils/ft_atoul.c utils/reduce.c utils/ft_utils.c\
				 signals/sinais.c signals/keyboard_handler.c\
				 close/clean_everything.c close/partial_close.c\
				 running/run.c running/pipeline_run.c running/exec_command.c running/exec_if_is_real.c\
				 running/path.c\
				 pipes/pipes_born.c pipes/is_not_forkable.c pipes/dup.c\
				 builtins/builtins.c builtins/builtins2.c builtins/builtins3.c\
				 redirect/redirects.c redirect/heredoc.c\
				 exp/exp.c exp/expnoexp.c\

OBJS_MINISHELL = $(SRCS_MINISHELL:.c=.o)

all: $(MINISHELL)

$(MINISHELL):	$(OBJS_MINISHELL)
				$(MAKE) -C ./libft
						$(CC) $(CCFLAGS) $(OBJS_MINISHELL) ./libft/libft.a -lreadline -o $(MINISHELL)

%.o: %.c
				$(CC) $(CCFLAGS) -c $< -o $@

clean:
				$(MAKE) clean -C ./libft
				rm -rf $(OBJS_MINISHELL)

fclean: clean
				$(MAKE) fclean -C ./libft
				rm -rf $(MINISHELL)

re: fclean all
