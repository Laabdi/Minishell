/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moaregra <moaregra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 02:42:43 by aelomari          #+#    #+#             */
/*   Updated: 2024/11/27 05:43:02 by moaregra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minishell.h"

void	add_to_array(char ***array, size_t *size, char *element);
int		skip_whitespace(char *line, int i);
void	init_words(t_words *words);
void	initialize_words(t_words *words);
int		count_filename_chars(char *line, int i);
void	parse_heredoc(t_words **words, char *line);
void	parse_infiles(t_words **words, char *line);
void	parse_append(t_words **words, char *line);
void	parse_outfiles(t_words **words, char *line);
void	parse_cmd_args(t_words **words, char *line);
int		is_quote_boundary(int *in_quotes, char *quote_char, char current_char);
void	quoting_str(char **line);
void	process_quote(const char *old_line, char *new_line);
void	process_word_array(char **word_array);
void	process_word_infiles(t_infile **infiles);
void	process_word_outfiles(t_outfile **outfiles);
void	add_to_array(char ***array, size_t *size, char *element);
void	add_to_infiles(t_infile **infiles, char *filename, t_red_type type,
			char *delimiter);
void	add_to_outfiles(t_outfile **outfiles, char *filename, t_red_type type,
			bool is_amred);