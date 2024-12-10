/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moaregra <moaregra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 10:19:49 by moaregra          #+#    #+#             */
/*   Updated: 2024/12/01 09:57:42 by moaregra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/Minishell.h"

void	ft_swap(t_env *env, t_env *to_swap)
{
	char	*tmp_value;
	char	*tmp_name;

	tmp_value = env->value;
	tmp_name = env->name;
	env->value = to_swap->value;
	env->name = to_swap->name;
	to_swap->value = tmp_value;
	to_swap->name = tmp_name;
}

void	env_sort(t_env **env)
{
	t_env	*tmp1;
	t_env	*tmp;

	tmp1 = *env;
	while (tmp1)
	{
		tmp = *env;
		while (tmp)
		{
			if (ft_strcmp(tmp1->name, tmp->name) < 0)
			{
				ft_swap(tmp1, tmp);
			}
			tmp = tmp->next;
		}
		tmp1 = tmp1->next;
	}
}

void	print_exportng(t_env *env)
{
	t_env	*tmp;

	tmp = env;
	while (tmp)
	{
		printf("declare -x ");
		printf("%s", tmp->name);
		if (*tmp->value)
			printf("=");
		printf("%s", tmp->value);
		printf("\n");
		tmp = tmp->next;
	}
}
