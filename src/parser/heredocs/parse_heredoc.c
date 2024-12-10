/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_heredoc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelomari <aelomari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 02:48:36 by aelomari          #+#    #+#             */
/*   Updated: 2024/12/02 20:40:57 by aelomari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/parsing.h"

char	*create_heredoc_filename(int count)
{
	char		*filename;
	const char	*prefix = HEREDOC_PREFIX;
	char		*ptr;

	filename = ft_malloc(ft_strlen(HEREDOC_PREFIX) + 2);
	ptr = filename;
	while (*prefix)
		*ptr++ = *prefix++;
	*ptr++ = 'a' + count;
	*ptr = '\0';
	return (filename);
}

static void	check_quoted_hd(char *delimiter)
{
	int	i;

	i = 0;
	while (delimiter[i])
	{
		if (delimiter[i] == '\'' || delimiter[i] == '"')
			get_var()->hd_quoted = TRUE;
		i++;
	}
}

char	*read_heredoc(char *delimiter)
{
	char	*line;
	char	*tmp;
	char	*result;

	check_quoted_hd(delimiter);
	between_quote(delimiter);
	quoting_str(&delimiter);
	result = ft_strdup("");
	while (1)
	{
		line = readline(">");
		if (!line || ft_strcmp(line, delimiter) == 0)
			return (free(line), free(delimiter), result);
		if (!get_var()->hd_quoted)
			expand_env_vars(&line);
		tmp = ft_strjoin(result, line);
		free(result);
		result = ft_strjoin(tmp, "\n");
		free(tmp);
		free(line);
	}
}

static int	process_heredoc(t_words **words, char *line, int i)
{
	char	*heredoc_filename;
	int		j;
	char	*delimiter;

	if (!words || !*words || !line)
		return (-1);
	i = skip_whitespace(line, i);
	j = count_filename_chars(line, i);
	delimiter = ft_malloc(j + 1);
	ft_strlcpy(delimiter, &line[i], j + 1);
	if (get_var()->count < MAX_HEREDOCS)
	{
		heredoc_filename = create_heredoc_filename(get_var()->count);
		add_to_infiles(&(*words)->infiles, heredoc_filename, HDOC, delimiter);
		free(heredoc_filename);
		get_var()->count++;
	}
	else
	{
		free(delimiter);
		return (thisisasynerror(ERROR_HERED), -1);
	}
	return (i + j);
}

void	parse_infiles_and_heredocs(t_words **words, char *line)
{
	int	i;

	get_var()->count = 0;
	i = 0;
	while (line[i])
	{
		if (line[i] == '<')
		{
			if (line[i + 1] == '<')
				i = process_heredoc(words, line, i + 2);
			else
				i = process_infile(words, line, i + 1);
		}
		else
			i++;
	}
}
