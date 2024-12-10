/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelomari <aelomari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 02:09:28 by aelomari          #+#    #+#             */
/*   Updated: 2024/09/28 02:10:34 by aelomari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/Minishell.h"

int	is_balanced_quotes(const char *line)
{
	int	in_single_quote;
	int	in_double_quote;

	in_single_quote = 0;
	in_double_quote = 0;
	while (*line)
	{
		if (*line == '\'' && !in_double_quote)
			in_single_quote = !in_single_quote;
		else if (*line == '\"' && !in_single_quote)
			in_double_quote = !in_double_quote;
		line++;
	}
	return (!in_single_quote && !in_double_quote);
}

void	ignore_inside(t_var *var)
{
	int	i;

	i = 0;
	while (i[var->line])
	{
		if (i[var->line] == '\"')
		{
			i++;
			while (i[var->line] != '\"')
				var->line[i++] *= -1;
		}
		i++;
	}
}
