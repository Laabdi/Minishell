/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelomari <aelomari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 03:53:48 by aelomari          #+#    #+#             */
/*   Updated: 2024/12/02 20:40:46 by aelomari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_pipe_data
{
	int					*fd;
	int					is_last;
}						t_pipe_data;

typedef void			t_unused;
typedef enum s_syntax_error
{
	ERROR_PIPES = (1 << 0),
	ERROR_PIPE2 = (1 << 1),
	ERROR_REDIR = (1 << 2),
	ERROR_REDI2 = (1 << 3),
	ERROR_HERED = (1 << 4),
	ERROR_MALLOC = (1 << 5),
}						t_syntax_error;

typedef enum s_red_type
{
	INPUT,
	OUTPUT,
	APPEND,
	HDOC,
}						t_red_type;
typedef enum e_file_mode
{
	READ_MODE,
	WRITE_TRUNC_MODE,
	WRITE_APPEND_MODE
}						t_file_mode;
// Structure to hold pipe information
typedef struct s_pipe_info
{
	int					**pipes;
	int					pipe_count;
	int					current_index;
}						t_pipe_info;

typedef struct s_outfile
{
	char				*filename;
	t_red_type			type;
	bool				ambiguous_red;
	struct s_outfile	*next;
}						t_outfile;

typedef struct s_infile
{
	char				*filename;
	bool				is_heredoc;
	char				*delimiter;
	t_red_type			type;
	struct s_infile		*next;
}						t_infile;

typedef struct s_quote_state
{
	int					i;
	int					j;
	bool				in_single_quote;
	bool				in_double_quote;
}						t_quote_state;

typedef struct s_word
{
	char				*cmd;
	char				**args;
	t_infile			*infiles;
	t_outfile			*outfiles;
}						t_words;
typedef struct s_env_path
{
	char				**path;
	char				**env;
	char				**export;
}						t_env_path;

typedef struct t_value
{
	char				*equal_sign;
	size_t				name_len;
	char				*name;
	char				*value;
}						t_value;

typedef struct s_pipeline
{
	t_words				*word;
	struct s_pipeline	*next;
	struct s_pipeline	*prev;
}						t_pipeline;
typedef struct s_env
{
	char				*name;
	char				*value;
	struct s_env		*next;
}						t_env;

typedef struct s_var
{
	t_pipeline			*pipeline;
	bool				in_heredoc;
	char				**c_path;
	char				*line;
	bool				synerrflag;
	int					status;
	t_syntax_error		error;
	t_env_path			*env_and_path;
	bool				in_single_quote_flag;
	t_quote_state		quote_state;
	int					count;
	t_env				*env;
	char				**enver;
	int					pipe_count;
	bool				is_ambiguous;
	pid_t				*pids;
	bool				hd_quoted;
}						t_var;

#endif