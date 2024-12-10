/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelomari <aelomari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 17:14:35 by aelomari          #+#    #+#             */
/*   Updated: 2024/11/13 15:00:01 by aelomari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/Minishell.h"

static void	process_single_quote(char *processed, t_quote_state *state,
		t_var *var)
{
	state->in_single_quote = !state->in_single_quote;
	var->in_single_quote_flag = true;
	processed[state->j++] = '\'';
}

static void	process_double_quote(char *processed, t_quote_state *state)
{
	state->in_double_quote = !state->in_double_quote;
	processed[state->j++] = '\"';
}

static int	process_line(char *line, char *processed, t_quote_state *state,
		t_var *var)
{
	while (line[state->i])
	{
		if (line[state->i] == '\'' && !state->in_double_quote)
			process_single_quote(processed, state, var);
		else if (line[state->i] == '\"' && !state->in_single_quote)
			process_double_quote(processed, state);
		else
			processed[state->j++] = line[state->i];
		state->i++;
	}
	return (state->j);
}

void	process_quotes(t_var *var)
{
	char	*processed;
	int		j;

	processed = ft_malloc(ft_strlen(var->line) * 2 + 1);
	if (!processed)
		return ;
	ft_bzero(&var->quote_state, sizeof(t_quote_state));
	var->in_single_quote_flag = false;
	j = process_line(var->line, processed, &var->quote_state, var);
	processed[j] = '\0';
	free(var->line);
	var->line = processed;
}

void	check_quoting(t_var *var)
{
	if (is_balanced_quotes(var->line))
	{
		if (ft_strcmp(var->line, "\"\"") == 0 || ft_strcmp(var->line,
				"''") == 0)
		{
			write(2, CMD_NOT_FOUND, ft_strlen(CMD_NOT_FOUND));
			return ;
		}
		process_quotes(var);
		ignore_inside(var);
	}
	else
	{
		ft_putstr_fd("Error: Unmatched quotes\n", 2);
		var->synerrflag = TRUE;
	}
}
