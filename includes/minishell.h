/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 10:08:24 by ablaamim          #+#    #+#             */
/*   Updated: 2022/07/27 19:49:48 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <string.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdbool.h>

/*
 * Debugers :
*/

void				print_env(char **env);

/*
 * Core functions :
*/

void				minishell(void);
char				*read_input(void);

/*
 * Libft_utils :
*/

char				*ft_strdup(char *str);
int					ft_strlen(char *str);
void				*ft_memset(void *memory, int c, size_t n);
void				ft_bzero(void *memory, size_t size);
int					ft_putstr_fd(int fd, char *str);
char				*ft_strcpy(char *dest, char *src);
bool				ft_iswhite_space(int c);
void				*ft_memcpy(void *dest, void *src, size_t n);
char				*ft_strndup(char *str, int n);

/*
 * Error handling utils :
*/

# define BUFFERING_SIZE 4096

typedef struct s_buffering
{
	int		i;
	char	buffer[BUFFERING_SIZE];
}	t_buffering;

typedef struct s_converter
{
	char	type;
	void	(*function)(t_buffering *, va_list);
}	t_converter;


int					variadic_error_printer(int fd, const char *fmt, ...);
char				*variadic_format_specifier(const char *str, va_list ap);
void				converter_percentage(t_buffering *format, va_list ap);
void				converter_character(t_buffering *format, va_list ap);
void				converter_string(t_buffering *format, va_list ap);

/*
 * Initialize bash envronment :
*/

typedef char	**t_env;

void				initialize_bash_env(t_env env);
int					env_length(t_env env);
t_env				*retrieve_bash_env(void);
void				initialize_env_variables(void);

/*
 * LEXER CLASS ABSTRACTION :
*/

/*
 * Must contain all possible char types.
*/

enum e_char_type
{
	ANY_CHAR,
	NULL_CHAR,
	SPACE_CHAR,
	SQUOTES_CHAR,
	DQUOTES_CHAR,
	LESS_CHAR,
	GREAT_CHAR,
	AND_CHAR,
	PIPE_CHAR,
	OP_PARENTH_CHAR,
	CLOSE_PARENTH_CHAR,
	NB_CHAR_TYPES
};

/*
 * Types of tokens handled by program, this will simplify parsing phase.
*/

enum e_token_type
{
	WORD_TOKEN,
	PIPE_TOKEN,
	OR_TOKEN,
	AND_TOKEN,
	LESSER_TOKEN,
	DLESSER_TOKEN,
	GREATER_TOKEN,
	DGREATER_TOKEN,
	OP_PARENTH_TOKEN,
	CLOSE_PARENTH_TOKEN
};

/*
 * Word token rules, its either accepted or not_accepted, this will be handful
 * in data filtring level.
*/

enum e_char_rules
{
	NOT_ACCEPTED,
	ACCEPTED
};

typedef struct s_token
{
	char				*data;
	enum e_token_type	type;
	struct s_token		*next;
}	t_token;

enum e_node_type
{
	SIMPLE_CMD,
	PIPE_NODE,
	OR_NODE,
	AND_NODE
};

typedef struct s_simple_cmd
{
	char	**argv;
	int		fd_input;
	int		fd_output;
	bool	input_has_quotes;
}	t_simple_cmd;

/*
 * ABSTRACT SYNTAX TREE :
*/

typedef struct s_child
{
	struct s_node	*left;
	struct s_node	*right;
}	t_child;

typedef struct s_node_content
{
	struct s_simple_cmd	simple_cmd;
	struct s_child		child;
}	t_node_content;

typedef struct s_node
{
	enum e_node_type	type;
	t_node_content		content;
}	t_node;

/*
 * LEXER / PARSER CLASS :
*/

void				executor(char *input);
t_node				*ft_lexer_parser(char *input);
bool				linked_list_constructor(char *input, t_token **token_list);
t_token				*retrieve_next_token(char *input, int *i);
enum e_char_type	define_char_type(char c);
enum e_char_rules	verifier(char c, bool *squotes_found, bool *dquotes_found);
t_token				*tokenize_word(char *input, int *i);
enum e_char_rules	apply_rules(enum e_char_type char_type);
t_token				*token_generator(char *data, enum e_token_type type);
void				append_token(t_token *new_token, t_token **token_list);
t_token				*tokenize_and(char *input, int *i);
t_token				*tokenize_pipe(char *input, int *i);
t_token				*tokenize_parenthesis(char *input, int *i);
t_token				*tokenize_greater(char *input, int *i);
t_token				*tokenize_lesser(char *input, int *i);
bool				check_logical_operators(enum e_token_type type);
void				devour_token(t_token **token_list);
void				tokens_free(t_token **token_list);
bool				print_err_and_return(t_token *token_list);

/*
 * Linked list debugger :
*/

void				print_linked_list_tokens(t_token *token);

/*
 * Abstract Syntax tree constructor class :
*/

bool				abstract_syntax_tree_constructor(t_token **token_list, \
		t_node **ast, bool	is_subshell);
bool				simple_command_parser(t_token **token_list, t_node **ast, \
		bool is_subshell);
bool				parse_pipe_line(t_token **token_list, t_node **ast, bool is_subshell);
bool				parser_parenthesis(t_token **token_list, t_node **ast);

#endif
