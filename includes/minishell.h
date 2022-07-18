/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 10:08:24 by ablaamim          #+#    #+#             */
/*   Updated: 2022/07/18 10:57:24 by ablaamim         ###   ########.fr       */
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
 * Core functions :
*/

/*
 *int		main(int argc, char **argv, char **env);
*/

/*
 * Debugers :
*/

void	print_env(char **env);
void	minishell(void);
char	*read_input(void);

/*
 * Libft_utils :
*/

char	*ft_strdup(char *str);
int		ft_strlen(char *str);
void	*ft_memset(void *memory, int c, size_t n);
void	ft_bzero(void *memory, size_t size);
int		ft_putstr_fd(int fd, char *str);
char	*ft_strcpy(char *dest, char *src);

/*
 * Error handling utils :
*/

#define BUFFERING_SIZE 4096

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

int		variadic_error_printer(int fd, const char *fmt, ...);
char	*variadic_format_specifier(const char *str, va_list ap);
void	converter_percentage(t_buffering *format, va_list ap);
void	converter_character(t_buffering *format, va_list ap);
void	converter_string(t_buffering *format, va_list ap);

/*
 * Initialize bash envronment :
*/

typedef char **t_env;

void	initialize_bash_env(t_env env);
int		env_length(t_env env);
t_env	*retrieve_bash_env(void);
void	initialize_env_variables(void);

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
	NB_CHAR_TYPES
};

/*
 * Types of tokens handled by program, this will simplify parsing phase.
*/

enum e_token_type
{
	WORD_TOKEN,
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
	enum e_token_type	type;;
	struct s_token		*next;
}	t_token;

enum e_node_type
{
	SIMPLE_CMD,
};

typedef struct s_simple_cmd
{
	char	**argv;
	int		fd_input;
	int		fd_output;
	bool	input_has_quotes;
}	t_simple_cmd;

/*
 * ABSTRAC T SYNTAX TREE :
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

void	executor(char *input);
t_node	*ft_lexer_parser(char *input);
bool	linked_list_constructor(char *input, t_token **token_list);

#endif
