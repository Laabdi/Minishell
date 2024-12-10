/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 07:33:53 by aelomari          #+#    #+#             */
/*   Updated: 2024/11/27 19:57:36 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/expand.h"

static void	handle_quotes(char c, t_quote_state *state)
{
	if (c == '\'' && !state->in_double_quote)
		state->in_single_quote = !state->in_single_quote;
	else if (c == '\"' && !state->in_single_quote)
		state->in_double_quote = !state->in_double_quote;
}

static void	copy_value(char *new_line, char **value, t_quote_state *state,
		int *w)
{
	int	k;

	k = 0;
	while (value[*w][k])
	{
		new_line[state->j] = value[*w][k];
		state->j++;
		k++;
	}
	(*w)++;
}

static void	process_char(char *new_line, char *line, t_quote_state *state)
{
	new_line[state->j] = line[state->i];
	state->i++;
	state->j++;
}

char	*get_new_line(char *line, char **variable, char **value)
{
	char			*new_line;
	t_quote_state	state;
	int				w;

	w = 0;
	new_line = ft_malloc(ft_strlen(line) - lendchar(variable) + lendchar(value)
			+ 2);
	ft_bzero(&state, sizeof(t_quote_state));
	while (line[state.i])
	{
		handle_quotes(line[state.i], &state);
		if (line[state.i] == '$' && !state.in_single_quote)
		{
			copy_value(new_line, value, &state, &w);
			state.i += ft_strlen(variable[w - 1]) + 1;
		}
		else
			process_char(new_line, line, &state);
	}
	new_line[state.j] = '\0';
	return (new_line);
}

char	*remove_dollar(char *line)
{
	int		i;
	int		j;
	char	*new_line;

	i = 0;
	j = 0;
	new_line = ft_malloc(ft_strlen(line) + 1);
	while (line[i])
	{
		if (line[i] == '$')
			i++;
		new_line[j++] = line[i++];
	}
	new_line[j] = '\0';
	return (new_line);
}
