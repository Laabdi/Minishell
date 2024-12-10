/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_envp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moaregra <moaregra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 16:15:11 by moaregra          #+#    #+#             */
/*   Updated: 2024/11/29 16:15:11 by moaregra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/Minishell.h"

static void	update_shlvl(t_env *envp)
{
	char	*new_value;

	if (ft_strcmp(envp->name, "SHLVL") == 0)
	{
		new_value = ft_itoa(ft_atoi(envp->value) + 1);
		if (new_value)
		{
			free(envp->value);
			envp->value = new_value;
		}
	}
}

void	store_in_env(char *s, t_env *envp)
{
	char	*index;
	int		len_name;
	int		len_value;

	if (!s || !envp)
		return ;
	index = ft_strchr(s, '=');
	if (!index)
		return ;
	len_name = index - s;
	len_value = ft_strlen(s) - len_name - 1;
	envp->name = malloc(len_name + 1);
	envp->value = malloc(len_value + 1);
	if (!envp->name || !envp->value)
	{
		free(envp->name);
		free(envp->value);
		return ;
	}
	ft_strlcpy(envp->name, s, len_name + 1);
	ft_strlcpy(envp->value, index + 1, len_value + 1);
	update_shlvl(envp);
}

t_env	*get_envp(char **env)
{
	t_env	*envp;
	t_env	*tmp;
	int		i;

	envp = NULL;
	i = 0;
	while (env[i])
	{
		tmp = malloc(sizeof(t_env));
		if (!tmp)
			return (NULL);
		store_in_env(env[i], tmp);
		ft_lstadd_backk(&envp, tmp);
		i++;
	}
	return (envp);
}
