/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelomari <aelomari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 15:17:50 by aelomari          #+#    #+#             */
/*   Updated: 2024/11/29 15:17:51 by aelomari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Minishell.h"

void	ft_env_add(t_env **env, char *name, char *value)
{
	t_env	*new;
	t_env	*tmp;

	new = (t_env *)ft_malloc(sizeof(t_env));
	new->name = name;
	if (ft_strcmp(name, "SHLVL") == 0)
		new->value = ft_itoa(ft_atoi(value) + 1);
	else
		new->value = value;
	new->next = NULL;
	if (!*env)
	{
		*env = new;
		return ;
	}
	tmp = *env;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

void	parse_env_vars(char **env)
{
	int	i;
	int	j;

	i = 0;
	while (env[i])
	{
		j = 0;
		while (env[i][j])
		{
			if (env[i][j] == '=')
				break ;
			j++;
		}
		if (env[i][j] == '=')
			ft_env_add(&get_var()->env, ft_substr(env[i], 0, j),
				ft_substr(env[i], j + 1, ft_strlen(env[i]) - j - 1));
		i++;
	}
}
