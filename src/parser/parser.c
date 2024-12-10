/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelomari <aelomari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 19:05:17 by aelomari          #+#    #+#             */
/*   Updated: 2024/12/02 21:20:46 by aelomari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parsing.h"

void	between_quote(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] < 0)
			line[i] *= -1;
		i++;
	}
}

t_words	*parser_words(char **line)
{
	t_words	*words;

	if (!*line)
		return (NULL);
	words = (t_words *)ft_malloc(sizeof(t_words));
	init_words(words);
	parse_infiles_and_heredocs(&words, *line);
	parse_outfiles_and_append(&words, *line);
	expand_env_vars(line);
	parse_cmd_args(&words, *line);
	return (words);
}

t_pipeline	*parser(t_var *var)
{
	t_pipeline	*pipeline;
	int			i;
	char		**pipel;

	i = 0;
	pipeline = NULL;
	pipel = ft_split(var->line, '|');
	while (pipel[i])
		pipe_addback(&pipeline, pipe_addnew(parser_words(&pipel[i++])));
	free_all(pipel);
	return (pipeline);
}
