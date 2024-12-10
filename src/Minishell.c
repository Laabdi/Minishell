/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moaregra <moaregra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 09:53:26 by aelomari          #+#    #+#             */
/*   Updated: 2024/12/02 23:47:12 by moaregra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Minishell.h"

void	signals(void)
{
	signal(SIGINT, sig_handler);
	signal(SIGQUIT, handle_sigquit);
}

void	minishell_loop(t_var *var)
{
	t_pipeline	*pipeline;

	if (*var->line)
		add_history(var->line);
	else
		return ;
	check_quoting(var);
	lexer(var);
	if (var->synerrflag == FALSE)
	{
		pipeline = parser(var);
		var->pipeline = pipeline;
		execute(var);
		free_pipeline(pipeline);
	}
	else
	{
		var->status = 258;
		return ;
	}
}

void	cntrl_d(t_var *var)
{
	if (!var->line)
	{
		printf("\nexit\n");
		free(var->line);
		free_env_list(&var->env);
		free(var);
		exit(0);
	}
}

int	main(int ac, char **av, char **env)
{
	t_var	*var;

	var = get_var();
	init(var, ac, av, env);
	while (1)
	{
		signals();
		var->line = readline(PROMPT);
		var->synerrflag = FALSE;
		cntrl_d(var);
		minishell_loop(var);
		free(var->line);
	}
	free_env_list(&var->env);
	free(var);
	return (0);
}
