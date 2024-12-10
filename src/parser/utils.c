/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moaregra <moaregra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 02:40:03 by aelomari          #+#    #+#             */
/*   Updated: 2024/11/27 05:42:41 by moaregra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parsing.h"

int	skip_whitespace(char *line, int i)
{
	while (ft_iswhite(line[i]))
		i++;
	return (i);
}

void	init_words(t_words *words)
{
	if (!words)
		return ;
	words->cmd = NULL;
	words->args = NULL;
	words->infiles = NULL;
	words->outfiles = NULL;
}

void	initialize_words(t_words *words)
{
	words->cmd = NULL;
	words->args = NULL;
}

int	count_filename_chars(char *line, int i)
{
	int	j;

	j = 0;
	while (!ft_iswhite(line[i + j]) && line[i + j] != '<' && line[i + j] != '>'
		&& line[i + j])
		j++;
	return (j);
}
