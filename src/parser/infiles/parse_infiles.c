/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_infiles.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelomari <aelomari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 03:03:21 by aelomari          #+#    #+#             */
/*   Updated: 2024/11/15 07:55:49 by aelomari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/parsing.h"

int	count_delimiter_chars(const char *line, int i)
{
	int	j;

	j = 0;
	while (!ft_iswhite(line[i + j]) && line[i + j] != '\0')
		j++;
	return (j);
}

int	process_infile(t_words **words, char *line, int i)
{
	char	*filename;
	int		j;

	i = skip_whitespace(line, i);
	j = count_delimiter_chars(line, i);
	filename = ft_malloc(j + 1);
	ft_strlcpy(filename, &line[i], j + 1);
	add_to_infiles(&(*words)->infiles, filename, INPUT, NULL);
	free(filename);
	return (i + j);
}
