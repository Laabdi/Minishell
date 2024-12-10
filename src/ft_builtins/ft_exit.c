/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelomari <aelomari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 10:20:00 by moaregra          #+#    #+#             */
/*   Updated: 2024/12/02 17:11:54 by aelomari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/Minishell.h"

void	ft_exit(char **args)
{
	int		count;
	t_var	*var;

	var = get_var();
	printf("exit\n");
	count = darr_count(args);
	if (count > 1)
		printf("minishell: exit: too many arguments\n");
	else if (count == 1)
		exit((unsigned char)ft_atoi(args[0]));
	else
	{
		free(var->pids);
		free(var->line);
		free_env_list(&var->env);
		free_pipeline(var->pipeline);
		free(var);
		exit(0);
	}
}
