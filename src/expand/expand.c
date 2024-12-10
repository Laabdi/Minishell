/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelomari <aelomari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 18:50:19 by aelomari          #+#    #+#             */
/*   Updated: 2024/12/02 19:37:08 by aelomari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/expand.h"

void	expand_env_vars(char **line)
{
	int		w;
	char	**variable;
	char	**value;
	char	*new_line;

	w = count_dollar(*line);
	if (w == 0)
		return ;
	variable = ft_malloc(sizeof(char *) * (w + 1));
	value = ft_malloc(sizeof(char *) * (w + 1));
	get_variable(*line, variable);
	get_value(variable, value);
	new_line = get_new_line(*line, variable, value);
	free_string_array(&variable);
	free_string_array(&value);
	free(*line);
	*line = new_line;
}
