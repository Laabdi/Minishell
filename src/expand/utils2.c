/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelomari <aelomari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 23:11:33 by aelomari          #+#    #+#             */
/*   Updated: 2024/12/02 15:55:44 by aelomari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/expand.h"

char	**get_variable(char *line, char **variable)
{
	int	i;
	int	j;
	int	variableindex;

	i = 0;
	variableindex = 0;
	while (line[i])
	{
		if (line[i] == '$')
		{
			i++;
			j = 0;
			while (line[i + j] && (ft_isalnum(line[i + j]) || line[i + j] == '_'
					|| line[i + j] == '?' || line[i] == '$')
				&& !ft_iswhite(line[i + j]) && line[i + j] != '\'' && line[i
					+ j] != '\"')
				j++;
			variable[variableindex++] = ft_substr(line, i, j);
			i += j;
		}
		else
			i++;
	}
	variable[variableindex] = NULL;
	return (variable);
}

char	*handle_special(char **variable, int i)
{
	if (!ft_strcmp(variable[i], "?"))
		return (ft_itoa(get_var()->status));
	else if (!ft_strcmp(variable[i], "$"))
		return (ft_itoa(getpid()));
	return (NULL);
}

char	**get_value(char **variable, char **value)
{
	int		i;
	char	*tmp;
	char	*env;

	i = 0;
	while (variable[i])
	{
		tmp = ft_strdup(variable[i]);
		quoting_str(&tmp);
		if (!ft_strcmp(tmp, "?") || !ft_strcmp(tmp, "$"))
			value[i] = handle_special(variable, i);
		else
		{
			env = my_getenv(tmp);
			if (env == NULL)
				value[i] = ft_strdup("");
			else
				value[i] = ft_strdup(my_getenv(tmp));
		}
		i++;
		free(tmp);
	}
	value[i] = NULL;
	return (value);
}
