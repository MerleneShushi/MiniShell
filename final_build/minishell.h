/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarrilh <dcarrilh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 12:03:23 by brolivei          #+#    #+#             */
/*   Updated: 2023/09/23 14:18:07 by dcarrilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "libft/libft.h"
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/types.h>
# include <sys/wait.h>

# define SYMBOLS	"<>\'\"| "
# define QUOTES	"\'\""
# define SPECIAL	"<>| "

/*          ENUMS          */

//		Classificacao dos tokens

typedef enum e_class
{
	IN_1,
	OUT_1,
	IN_2,
	OUT_2,
	PIPE,
	SINGLE_QUOTES,
	DOUBLE_QUOTES,
	TERM,
}			t_class;

/*          STRUCTS          */

//		Estrutura de token

typedef struct s_token
{
	char	*str;
	int		can_merge;
	t_class	type;
}				t_token;

// Estrutura de variavel de ambiente

typedef struct s_env
{
	char	*name;
	char	*info;
}				t_env;

// Estrutura arvore sintatica abstrata
	// Token correspondente ao nodulo.
	// Argumentos do token.
	// Usado caso o token represente um comando.
	// Nodulo esquerdo do nodulo atual.
	// Nodulo direito do nodulo atual.

typedef struct s_ast
{
	t_token			*token;
	char			**args;
	int				index;
	struct s_ast	*left;
	struct s_ast	*right;
}				t_ast;

// Linked list of environment variables.
// Linked list of export variables.;
// Linked list of tokens.

typedef struct ms
{
	int		fd_in;
	int		fd_out;
	int		exit_status;
	int		num_commands;
	int		**pipes;
	char	*input;
	char	*pwd;
	char	**path;
	char	**env_matrix;
	t_list	*envlist;
	t_list	*explist;
	t_list	*tokens;
	t_ast	*ast;
}				t_ms;

/*          FUNC          */

// Simulacao de variavel global, estrutura total do minishell.
t_ms				*ms(void);

// PROMPT

void				start(void);

void				prompt(void);

// ENVS

t_env				*create_env_node(char *envp);

t_list				*ft_env(char **envp);

void				destroy_env(t_env *env);

void				deallocate_env_list(t_list *root);

void				update_envs(void);

char				*get_env(char *name);

// EXPORT

t_list				*ft_exp(char **envp);

t_env				*create_exp_node(char *envp);

char				*exp_info_node(t_env *exp, char *envp);

char				*exp_name_node(t_env *exp, char *envp);

t_list				*ft_sort_exp(t_list *head);

// ADD EXPORT

void				ft_expnoexp(void);

void				ft_addexp(char *token);

int					ft_strcmp_exp(char *s1, char *s2, char a);

void				ft_printexp(void);

void				ft_addenv(char *token);

// LEXER

int					lexical_analysis(char	*input);

t_list				*lexer(char *input);

int					lexer_push_token(char *str, t_class class,
						int can_merge, t_list **lst_tokens);

int					lexer_find_match(char *match, char *input, t_list **tokens);

int					is_mergeable(char *str, char *match, int jump);

// ANALISE SINTATICA

int					token_analysis(t_list *tokens);

int					is_redir(t_token *token);

int					is_pipe(t_token *token);

int					is_redir_or_pipe(t_token *token);

// TOKENS

t_token				*token_new(char *str, t_class class, int can_merge);

void				token_destroy(t_token *token);

t_token				*token_copy(t_token *token);

void				deallocate_token_list(t_list *root);

// EXPANDER

void				expand_variable(t_token *token,
						t_list *envlist, int exit_status);

void				expander(t_list *tokens, t_list *envlist, int exit_status);

char				*find_key(char *str);

char				*get_env_exp(char *key, t_list *envlist);

void				merge_tokens(t_list *tokens);

// PARSER

t_ast				*parser(t_ms *ms);

t_ast				*extend_command(t_ast *command, t_ms *ms);

t_ast				*extend_pipeline(t_ast *ast, t_ast *command);

t_ast				*parse_command(t_ms *ms);

t_ast				*parse_pipeline(t_ms *ms);

// AST

void				deallocate_ast(t_ast *node);

void				ast_insert(t_ast **ast, t_ast *node, int left);

t_ast				*ast_new(t_token *token);

// MATRIX

char				**matrix_append(char **m1, char *str);

void				array_destroy(void	*array);

void				array_destroy_ints(int **array);

int					matrix_size(char **mat);

// PIPES

void				pipeline_create(void);

pid_t				pipeline_run(t_ast *node);

void				pipeline_apply(int command_index);

// RUN

void				run(t_ast *ast);

void				exec_command(char **args);

int					is_not_forkable(char *command, char *arg);

int					is_builtin(char *command);

void				exec_if_is_real(char *exe, char **argv);

char				*get_executable_path(char *exe);

int					is_last_command(int command_index);

// SINAIS

void				signals(void);

void				signals_child(void);

void				signals_heredoc(void);

void				handler_sigint(int signum);

void				handler_child(int signum);

void				handler_heredoc(int signum);

void				signals_ignore(void);

// CLOSE

void				clean_everything(void);

void				partial_close(void);

// Builtins

void				ft_exit(char **args);

void				ft_pwd(void);

void				ft_myenv(char **args);

void				ft_echo(char **args);

void				ft_unset(char **args);

void				ft_myexp(char **args);

void				ft_cd(char **args);

// DUP

void				connect(void);

void				disconnect(int command_index);

// REDIRECTS

int					is_redirection(t_token *token);

void				exec_redirection(t_class type, char *file);

int					heredoc(char *flag);

void				heredoc_reader(char *flag);

char				*heredoc_expand(char *input);

// UTILS

t_token				*scanner(char *str, t_ms *ms);

int					is_spaces(const char *input);

int					ft_strlen_sep(const char *s, char *seps);

char				*ft_strreplace(char *str, char *old, char *new);

int					handle_error(char *msg, char *extra, int status);

unsigned long long	ft_atoul(const char *str);

void				ft_exit_reduce(char **args, int control);

void				ft_cd_reduce(char **args);

void				ft_del_exp_reduce2(t_env **new_node, t_list **head,
						t_list **current, t_list *previous);

int					ft_del_exp_red(t_env *exp_node, t_env *new_node, int x);

int					ft_addexp_red(t_env *curr, t_env *new_node, int x);

int					ft_strcmp_exp(char *s1, char *s2, char a);

int					ft_exp_name_valid(char *arg);

int					ft_echo_red(char	**args);

#endif
