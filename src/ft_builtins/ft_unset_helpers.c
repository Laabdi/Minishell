/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset_helpers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moaregra <moaregra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 16:04:47 by moaregra          #+#    #+#             */
/*   Updated: 2024/11/29 16:16:28 by moaregra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/Minishell.h"

char	*get_variable_name(char *s)
{
	char	*result;
	char	*finder;
	int		len;

	finder = ft_strchr(s, '=');
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

void	ft_remove(t_env **env, t_env *to_remove)
{
	t_env	*current;

	if (!*env || !to_remove)
		return ;
	if (*env == to_remove)
	{
		*env = to_remove->next;
		free(to_remove->name);
		free(to_remove->value);
		free(to_remove);
		return ;
	}
	current = *env;
	while (current && current->next != to_remove)
		current = current->next;
	if (current && current->next)
	{
		current->next = to_remove->next;
		free(to_remove->name);
		free(to_remove->value);
	}
}

int	is_valid_unset_input(t_env **env, char *av)
{
	if (!env || !*env || !av)
		return (0);
	return (1);
}
