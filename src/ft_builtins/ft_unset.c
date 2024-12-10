/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moaregra <moaregra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 10:20:04 by moaregra          #+#    #+#             */
/*   Updated: 2024/11/29 16:08:41 by moaregra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/Minishell.h"

static int	remove_env_node(t_env **env, t_env *tmp, t_env *prev, char *to_find)
{
	(void)to_find;
	if (prev)
		prev->next = tmp->next;
	else
		*env = tmp->next;
	free(tmp->name);
	free(tmp->value);
	free(tmp);
	return (1);
}

static void	ft_unset_onestring(t_env **env, char *av)
{
	t_env	*tmp;
	t_env	*prev;
	char	*to_find;

	if (!is_valid_unset_input(env, av))
		return ;
	tmp = *env;
	prev = NULL;
	to_find = get_variable_name(av);
	if (!to_find)
		return ;
	while (tmp)
	{
		if (ft_strncmp(to_find, tmp->name, ft_strlen(to_find)) == 0)
		{
			remove_env_node(env, tmp, prev, to_find);
			if (to_find != av)
				free(to_find);
			return ;
		}
		prev = tmp;
		tmp = tmp->next;
	}
	if (to_find != av)
		free(to_find);
}

void	ft_unset(t_env **env, char **av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		ft_unset_onestring(env, av[i]);
		i++;
	}
}
