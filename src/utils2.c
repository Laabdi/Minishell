/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moaregra <moaregra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 17:13:53 by aelomari          #+#    #+#             */
/*   Updated: 2024/11/27 05:38:25 by moaregra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Minishell.h"

t_var	*get_var(void)
{
	static t_var	*var;

	if (var == NULL)
	{
		var = (t_var *)ft_malloc(sizeof(t_var));
	}
	return (var);
}

void	replace_between_quotes(t_var *var)
{
	int	in_quotes;
	int	i;

	in_quotes = 0;
	i = 0;
	while (i[var->line])
	{
		if (i[var->line] == '\"' || i[var->line] == '\'')
		{
			in_quotes = !in_quotes;
			continue ;
		}
		if (in_quotes)
			i[var->line] = ' ';
		i++;
	}
}

static void	process_char(char **ptr, char *line, int *in_quotes,
		char *quote_char)
{
	if (!*in_quotes && (*line == '\'' || *line == '\"'))
	{
		*in_quotes = 1;
		*quote_char = *line;
	}
	else if (*in_quotes && *line == *quote_char)
	{
		*in_quotes = 0;
		*quote_char = '\0';
	}
	else
		*(*ptr)++ = *line;
}

void	quoting(t_var *var)
{
	char	*new_line;
	char	*ptr;
	int		i;
	int		in_quotes;
	char	quote_char;

	new_line = ft_malloc(ft_strlen(var->line) + 1);
	ptr = new_line;
	i = 0;
	in_quotes = 0;
	quote_char = '\0';
	while (var->line[i] != '\0')
	{
		process_char(&ptr, &var->line[i], &in_quotes, &quote_char);
		i++;
	}
	*ptr = '\0';
	free(var->line);
	var->line = new_line;
}
