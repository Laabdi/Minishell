/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution6.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moaregra <moaregra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 23:48:28 by moaregra          #+#    #+#             */
/*   Updated: 2024/12/02 23:49:03 by moaregra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/Minishell.h"

void	free_child_resources(t_var *var, char **cmd, char **env)
{
	free(cmd);
	free_env_list(&var->env);
	free_pipeline(var->pipeline);
	free(var->line);
	free_string_array(&env);
	free(var->pids);
	free(var);
}

void	sig_hh(int test)

{
	(t_unused) test;
	printf("\n");
}

void	sig_hhh(int hhh)
{
	(t_unused) hhh;
	write(STDOUT_FILENO, "Quit (core dumped)\n", 19);
}
