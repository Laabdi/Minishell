/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_helpers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moaregra <moaregra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 15:50:16 by moaregra          #+#    #+#             */
/*   Updated: 2024/12/01 09:06:00 by moaregra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/Minishell.h"

int	var_without_equal(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '=' || s[i] == '+')
			return (1);
		i++;
	}
	return (0);
}

int	is_exportable(char *s)
{
	int	i;

	i = 0;
	if (var_without_equal(s))
		if (!s || s[0] == '\0')
			return (0);
	if (!(ft_isalpha(s[0]) || s[0] == '_'))
		return (0);
	while (s[i] && s[i] != '=')
	{
		if (!(ft_isalnum(s[i]) || s[i] == '_'))
			return (0);
		i++;
	}
	if (s[i] != '=')
		return (0);
	return (1);
}

int	already_exist(t_env *env, char *s)
{
	t_env	*tmp;

	tmp = env;
	while (tmp)
	{
		if (ft_strcmp(s, tmp->name) == 0)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	update_env(char *s, t_env *env)
{
	t_env	*tmp;
	char	*name;
	char	*value;

	tmp = env;
	name = get_variable_name(s);
	value = ft_strchr(s, '=') + 1;
	while (tmp)
	{
		if (ft_strcmp(name, tmp->name) == 0)
		{
			free(tmp->value);
			tmp->value = ft_strdup(value);
			free(name);
			return ;
		}
		tmp = tmp->next;
	}
}
