/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelomari <aelomari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 06:48:02 by aelomari          #+#    #+#             */
/*   Updated: 2024/12/01 07:59:43 by aelomari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/Minishell.h"

int	is_quote_boundary(int *in_quotes, char *quote_char, char current_char)
{
	if (!*in_quotes && (current_char == '\'' || current_char == '\"'))
	{
		*in_quotes = 1;
		*quote_char = current_char;
		return (1);
	}
	else if (*in_quotes && current_char == *quote_char)
	{
		*in_quotes = 0;
		*quote_char = '\0';
		return (1);
	}
	return (0);
}

void	process_quote(const char *old_line, char *new_line)
{
	int		i;
	int		j;
	int		in_quotes;
	char	quote_char;

	i = 0;
	j = 0;
	in_quotes = 0;
	quote_char = '\0';
	while (old_line[i] != '\0')
	{
		if (is_quote_boundary(&in_quotes, &quote_char, old_line[i]))
		{
			i++;
			continue ;
		}
		new_line[j++] = old_line[i++];
	}
	new_line[j] = '\0';
}

void	quoting_str(char **line)
{
	char	*new_line;
	size_t	len;

	if (!line || !*line)
		return ;
	len = ft_strlen(*line);
	new_line = ft_malloc(len + 1);
	if (!new_line)
	{
		free(*line);
		*line = NULL;
		return ;
	}
	process_quote(*line, new_line);
	free(*line);
	*line = new_line;
}
