/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moaregra <moaregra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 10:31:50 by aelomari          #+#    #+#             */
/*   Updated: 2024/12/02 23:47:19 by moaregra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Minishell.h"

void	envcpy(char **enver, char **env)
{
	int	i;
	int	j;

	i = 0;
	enver = (char **)ft_malloc(sizeof(char *) * (darr_count(env) + 1));
	while (env[i])
	{
		enver[i] = (char *)ft_malloc(sizeof(char) * (ft_strlen(env[i]) + 1));
		j = 0;
		while (env[i][j])
		{
			enver[i][j] = env[i][j];
			j++;
		}
		enver[i][j] = '\0';
		i++;
	}
}

void	init(t_var *var, int ac, char **av, char **env)
{
	(t_unused) ac;
	(t_unused) av;
	var->enver = env;
	var->env = NULL;
	var->env = get_envp(env);
	var->in_heredoc = FALSE;
	var->synerrflag = FALSE;
	var->hd_quoted = FALSE;
}

void	sig_handler(int signo)
{
	if (signo == SIGINT)
	{
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
		get_var()->status = 128 + SIGINT;
	}
}

void	handle_sigquit(int signo)
{
	if (signo == SIGQUIT)
	{
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
		get_var()->status = 128 + SIGQUIT;
	}
}
