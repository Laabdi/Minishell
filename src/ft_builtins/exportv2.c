/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exportv2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moaregra <moaregra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 10:19:53 by moaregra          #+#    #+#             */
/*   Updated: 2024/11/29 13:02:26 by moaregra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/Minishell.h"

int	check_export_with_plus(char *av)
{
	char	*index;

	if (!av)
		return (0);
	index = ft_strchr(av, '=');
	if (!index || index == av)
		return (0);
	if (*(index - 1) == '+')
		return (1);
	return (0);
}

char	*get_variable_name_exportplus(char *s)
{
	char	*result;
	char	*finder;
	int		len;

	finder = ft_strchr(s, '+');
	if (!finder)
		return (s);
	len = finder - s;
	result = malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	ft_strncpy(result, s, len);
	result[len] = '\0';
	return (result);
}

char	*get_variable_value(char *s)
{
	int		i;
	int		k;
	int		j;
	char	*result;

	i = 0;
	k = 0;
	while (s[i] != '=' && s[i])
		i++;
	if (s[i] == '=' && s[i + 1])
		i++;
	else
		return (0);
	j = i;
	while (s[i])
		i++;
	result = malloc(sizeof(char) * (i - j) + 1);
	if (!result)
		return (0);
	while (j < i)
		result[k++] = s[j++];
	result[k] = '\0';
	return (result);
}

void	export_with_plus(t_env **env, char *av)
{
	char	*tmp_s;
	char	*variable_name;
	char	*variable_value;
	t_env	*tmp;

	tmp = *env;
	variable_name = get_variable_name_exportplus(av);
	variable_value = get_variable_value(av);
	if (check_export_with_plus(av) != 0)
	{
		while (tmp)
		{
			if (ft_strcmp(tmp->name, variable_name) == 0)
			{
				tmp_s = ft_strjoin(tmp->value, variable_value);
				free(tmp->value);
				tmp->value = ft_strdup(tmp_s);
				free(tmp_s);
			}
			tmp = tmp->next;
		}
	}
	free(variable_name);
	free(variable_value);
}
