/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_append.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelomari <aelomari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 03:09:17 by aelomari          #+#    #+#             */
/*   Updated: 2024/11/07 01:25:26 by aelomari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/parsing.h"

// static int	process_append(t_words **words, char *line, int i, size_t *size)
// {
// 	char	*filename;
// 	int		j;

// 	i = skip_whitespace(line, i);
// 	j = count_filename_chars(line, i);
// 	filename = ft_malloc(j + 1);
// 	ft_strlcpy(filename, &line[i], j + 1);
// 	add_to_array(&(*words)->outfiles_append, size, filename);
// 	return (i + j);
// }

// void	parse_append(t_words **words, char *line)
// {
// 	int		i;
// 	size_t	size;

// 	i = 0;
// 	size = 0;
// 	(*words)->outfiles_append = NULL;
// 	while (line[i])
// 	{
// 		if (line[i] == '>' && line[i + 1] == '>')
// 			i = process_append(words, line, i + 2, &size);
// 		else
// 			i++;
// 	}
// 	add_to_array(&(*words)->outfiles_append, &size, NULL);
// }
