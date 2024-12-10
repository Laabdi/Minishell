/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelomari <aelomari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 07:33:15 by aelomari          #+#    #+#             */
/*   Updated: 2024/11/15 07:56:13 by aelomari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/expand.h"

int	count_dollar(char *line)
{
	int	i;
	int	count;
	int	in_single_quotes;
	int	in_double_quotes;

	i = 0;
	count = 0;
	in_single_quotes = 0;
	in_double_quotes = 0;
	while (line[i])
	{
		if (line[i] == '\'' && !in_double_quotes)
			in_single_quotes = !in_single_quotes;
		else if (line[i] == '\"' && !in_single_quotes)
			in_double_quotes = !in_double_quotes;
		else if (line[i] == '$')
		{
			if (!in_single_quotes)
				count++;
		}
		i++;
	}
	return (count);
}

int	lendchar(char **arr)
{
	int	total_len;
	int	i;

	total_len = 0;
	i = 0;
	while (arr[i])
	{
		total_len += ft_strlen(arr[i]);
		i++;
	}
	return (total_len);
}

char	*my_getenv(const char *name)
{
	t_env	*envp;

	envp = get_var()->env;
	if (envp == NULL || name == NULL)
		return (NULL);
	while (envp)
	{
		if (ft_strcmp(envp->name, name) == 0)
			return (envp->value);
		envp = envp->next;
	}
	return (NULL);
}
