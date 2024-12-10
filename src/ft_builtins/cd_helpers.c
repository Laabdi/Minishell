/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_helpers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moaregra <moaregra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 10:19:44 by moaregra          #+#    #+#             */
/*   Updated: 2024/11/27 10:19:45 by moaregra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/Minishell.h"

char	*get_old_path(void)
{
	char	old_path[4096];

	if (getcwd(old_path, sizeof(old_path)) == NULL)
		return (NULL);
	return (ft_strdup(old_path));
}

char	*get_new_path(void)
{
	char	new_path[4096];

	if (getcwd(new_path, sizeof(new_path)) == NULL)
		return (NULL);
	return (ft_strdup(new_path));
}

void	update_new_path(t_env **env, char *new_path)
{
	t_env	*tmp;
	char	*old_value;

	if (!env || !new_path)
		return ;
	tmp = *env;
	while (tmp)
	{
		if (ft_strncmp(tmp->name, "PWD", 3) == 0 && tmp->name[3] == '\0')
		{
			old_value = tmp->value;
			tmp->value = ft_strdup(new_path);
			free(old_value);
			break ;
		}
		tmp = tmp->next;
	}
}

void	update_old_path(t_env **env, char *old_path)
{
	t_env	*tmp;
	char	*old_value;

	if (!env || !old_path)
		return ;
	tmp = *env;
	while (tmp)
	{
		if (ft_strncmp(tmp->name, "OLDPWD", 6) == 0 && tmp->name[6] == '\0')
		{
			old_value = tmp->value;
			tmp->value = ft_strdup(old_path);
			free(old_value);
			break ;
		}
		tmp = tmp->next;
	}
}
