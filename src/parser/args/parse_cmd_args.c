/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd_args.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 03:10:51 by aelomari          #+#    #+#             */
/*   Updated: 2024/09/29 20:45:09 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/parsing.h"

static int	count_arg_chars(char *line, int i)
{
	int	j;

	j = 0;
	while (line[i + j] && !ft_iswhite(line[i + j]) && line[i + j] != '<'
		&& line[i + j] != '>')
		j++;
	return (j);
}

static int	process_argument(t_words **words, char *line, int i,
		size_t *args_size)
{
	char	*arg;
	int		j;

	j = count_arg_chars(line, i);
	if (j > 0)
	{
		arg = ft_malloc(j + 1);
		ft_strlcpy(arg, &line[i], j + 1);
		arg[j] = '\0';
		if ((*words)->cmd == NULL)
			(*words)->cmd = arg;
		else
			add_to_array(&(*words)->args, args_size, arg);
		return (i + j);
	}
	return (i + 1);
}

static int	skip_redirection(char *line, int i)
{
	i++;
	if (line[i] == '<' || line[i] == '>')
		i++;
	i = skip_whitespace(line, i);
	while (line[i] && !ft_iswhite(line[i]))
		i++;
	return (i);
}

void	parse_cmd_args(t_words **words, char *line)
{
	int		i;
	size_t	args_size;

	i = 0;
	args_size = 0;
	initialize_words(*words);
	while (line[i])
	{
		if (line[i] == '<' || line[i] == '>')
			i = skip_redirection(line, i);
		else
			i = process_argument(words, line, i, &args_size);
	}
	add_to_array(&(*words)->args, &args_size, NULL);
}
