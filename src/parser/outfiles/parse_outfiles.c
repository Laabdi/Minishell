/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_outfiles.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelomari <aelomari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 03:07:08 by aelomari          #+#    #+#             */
/*   Updated: 2024/11/15 07:54:34 by aelomari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/parsing.h"

static int	process_outfile(t_words **words, char *line, int i, bool is_append)
{
	char	*filename;
	int		j;

	i = skip_whitespace(line, i);
	j = count_filename_chars(line, i);
	filename = ft_malloc(j + 1);
	ft_strlcpy(filename, &line[i], j + 1);
	if (is_append)
		add_to_outfiles(&(*words)->outfiles, filename, APPEND, FALSE);
	else
		add_to_outfiles(&(*words)->outfiles, filename, OUTPUT, FALSE);
	free(filename);
	return (i + j);
}

void	parse_outfiles_and_append(t_words **words, char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '>')
		{
			if (line[i + 1] == '>')
				i = process_outfile(words, line, i + 2, true);
			else
				i = process_outfile(words, line, i + 1, false);
		}
		else
			i++;
	}
}
