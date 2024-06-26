/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adhaka <adhaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:20:13 by eweiberl          #+#    #+#             */
/*   Updated: 2023/12/04 09:51:12 by adhaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/* ************************************************************************** */
/*                                Libraries                                   */
/* ************************************************************************** */

# include "libft/libft.h"
# include "libmock/mock_functions.h"

# include <stdio.h>
# include <signal.h>
# include <stdbool.h>
# include <stdlib.h>
# include <termios.h>
# include <errno.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>

/* ************************************************************************** */
/*                            Defines & enums                                 */
/* ************************************************************************** */

enum e_token
{
	CMD = 0,
	BUILTIN,
	ARGUMENT,
	CONTENT,
	REDIRECT,
	PIPE,
	FD,
	HERE_DOC,
	LIMITER,
	SEMICOLON
};

# define STDIN 0
# define STDOUT 1
# define STDERR 2

extern int	g_last_exit_status;
/* ************************************************************************** */
/*                          Typedefs and globals                              */
/* ************************************************************************** */

typedef struct s_command
{
	int		in_fd;
	int		out_fd;
	char	*cmd_name;
	char	**cmd;
	char	*input_file;
	char	*output_file;
}	t_command;

typedef struct s_token
{
	char			*cmd;
	int				operation;
	t_command		*table;
	int				tmp;
	struct s_token	*next;
	struct s_token	*prev;
}	t_token;

typedef struct s_exec
{
	char				**cmds;
	int					in_fd;
	int					out_fd;
}	t_exec;

typedef struct s_env
{
	char			*var;
	struct s_env	*next;
}	t_env;

/* ************************************************************************** */
/*                                Executing                                   */
/* ************************************************************************** */

void	executor(t_exec **exec, t_env *env);
void	execute_last_command(t_exec **exec, t_env *env, int tmp, int i);
void	execute_command(t_exec *exec, t_env *env, int *tmp, int *fd);
void	handle_dup(int *tmp);
void	close_fds(t_exec **exec, int i);
char	*get_cmd_path(char *cmd, char **path);
char	**get_path(char	**envp);
char	*correct(t_exec *exec, char **envp);
void	ex(t_exec *exec, t_env *env, int tmp);

t_exec	**commands_for_exec(t_token *tokens);
int		execute_cmd(char **cmd, char **envp);
int		here_doc(t_env *env_list, char *delim);
void	fill(t_exec *exec, t_token *tokens, int n_tokens);
int		cmd_counter(t_token *tokens);
void	execute_child(int *fd, t_exec *exec, t_env *env, int *tmp);
void	execute_last_child(t_exec **exec, t_env *env, int tmp, int i);
void	execute_last_parent(pid_t pid, int status);

/* ************************************************************************** */
/*                                builtins                                    */
/* ************************************************************************** */

int		execute_builtin(char **split, t_env *env_list, t_exec **exec);
bool	is_builtin(char *cmd);
int		builtin_env(t_env *env_list);
int		builtin_pwd(t_env *env_list);
int		builtin_cd(char **cmds, t_env *env_list);
int		builtin_echo(char **split, char *str);
int		builtin_export(char **split, t_env *env_list);
int		builtin_unset(char **split, t_env *env_list);
int		builtin_exit(char **split, t_env *env_list, t_exec **executable);

/* ************************************************************************** */
/*                                  Lexer                                     */
/* ************************************************************************** */

void	free_tokens(t_token **token_list);
bool	is_redirect(char *cmd);
t_token	*tokenizer(char *input);
void	assign_id(t_token *token_list);
bool	is_builtin(char *cmd);
int		pipe_checker(char *tmp, int i);
void	fix_tokens(t_token *tokens);
int		lexer_redirects(int i, char *input);

/* ************************************************************************** */
/*                                  Parser                                    */
/* ************************************************************************** */

int		mainpars(t_token *tokens, t_env *env);
char	**my_split(char *str);
int		word_len(char *str, int i);
int		ft_open(char *str, int flag);
int		cmd_maker(t_token *tokens);
int		cmd_maker2(t_token *tokens);
int		red_maker(t_token *tokens, int flag);
int		red_maker2(t_token *tokens);
int		in_out(char *str, t_token *tmp, int flag);
void	free_exec_array(t_exec **exec);
int		in_out(char *str, t_token *tmp, int flag);
int		handling(t_token *tokens);
int		ft_open(char *str, int flag);
int		h_doc(t_token *tokens, t_env *env);
int		red_maker_extension(t_token *tokens, t_token *tmp);
int		qcheck(t_token *tokens);

/* ************************************************************************** */
/*                                  Expander                                  */
/* ************************************************************************** */

char	*expander(char *arg, t_env *env_list, int i, bool in_quotes);
int		expand_tokens(t_env *env_list, t_token *tokens);
bool	set_in_quotes(bool in_quotes);
int		get_exit_signal(void);

/* ************************************************************************** */
/*                                 Environment                                */
/* ************************************************************************** */

t_env	*env_init(char **envp);
void	free_env_struct(t_env **env_list);
int		env_size(t_env *env_list);
int		rem_env_var(char *name, t_env **env_list);
int		replace_env_var(char *name, char *value, t_env *env_list);
char	*get_env_var(char *name, t_env *env_list);
char	**env_get_envp(t_env *env_list);

/* ************************************************************************** */
/*                                  Utils                                     */
/* ************************************************************************** */

char	*get_prompt(void);
char	**ft_split_minishell(char const *s, char c);
void	free_strings(void **strings);
int		ft_isblank(char c);
int		ft_isquote(char c);
int		rem_quotes(char **split);

/* ************************************************************************** */
/*                                  Signals                                   */
/* ************************************************************************** */

void	ctrl_c(void);
void	ctrl_bs(void);
void	sig_type(int sig);
void	clear_sigargs(void);
void	block_signal(void);

/* ************************************************************************** */
/*                               test_fuctions                                */
/* ************************************************************************** */

/*
** functions needed for testing purposes, name should start with t_
*/
void	t_print_tokens(t_token *tokens);
void	t_print_env_struct(t_env *environment_list);

#endif
