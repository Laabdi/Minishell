/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelomari <aelomari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 10:19:30 by moaregra          #+#    #+#             */
/*   Updated: 2024/12/02 21:19:27 by aelomari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/Minishell.h"

int	handle_existing_var(char *s, t_env **env, char *name)
{
	if (already_exist(*env, name))
	{
		update_env(s, *env);
		free(name);
		return (1);
	}
	free(name);
	return (0);
}

void	add_new_env_var(char *s, t_env **env)
{
	t_env	*tmp;

	tmp = malloc(sizeof(t_env));
	if (!tmp)
		return ;
	store_in_env(s, tmp);
	ft_lstadd_backk(env, tmp);
}

void	add_special_var(char *s, t_env **env)
{
	t_env	*tmp;

	tmp = *env;
	while (tmp)
	{
		if (ft_strcmp(s, tmp->name) == 0)
			return ;
		else
		{
			tmp = malloc(sizeof(t_env));
			if (!tmp)
				return ;
			tmp->name = ft_strdup(s);
			tmp->value = ft_strdup("");
			ft_lstadd_backk(env, tmp);
		}
		tmp = tmp->next;
	}
}

static int	export_noarg(char **s, t_env **env)
{
	if (!s[0])
	{
		env_sort(env);
		print_exportng(*env);
		return (1);
	}
	return (0);
}

void	export_to_env(char **s, t_env **env)
{
	int		i;

	if (export_noarg(s, env) == 1)
		return ;
	i = -1;
	while (s[++i])
	{
		if (check_export_with_plus(s[i]) != 0)
			export_with_plus(env, s[i]);
		else
		{
			if (var_without_equal(s[i]) == 0)
			{
				add_special_var(s[i], env);
				continue ;
			}
			else if (!is_exportable(s[i]))
				return ((void)printf("unexportable value\n"));
			if (handle_existing_var(s[i], env, get_variable_name(s[i])))
				continue ;
			add_new_env_var(s[i], env);
		}
	}
}
