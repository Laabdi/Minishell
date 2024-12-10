/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exeuction4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moaregra <moaregra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 22:54:53 by moaregra          #+#    #+#             */
/*   Updated: 2024/12/02 23:00:36 by moaregra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/Minishell.h"

char	**handle_cmd(t_pipeline *pipeline)
{
	int		arg_count;
	char	**cmd;
	int		i;

	i = 0;
	arg_count = darr_count(pipeline->word->args);
	cmd = malloc(sizeof(char *) * (arg_count + 2));
	cmd[0] = get_cmd(pipeline->word->cmd);
	while (i < arg_count)
	{
		cmd[i + 1] = pipeline->word->args[i];
		i++;
	}
	cmd[arg_count + 1] = NULL;
	return (cmd);
}

int	pipe_count(t_pipeline *pipeline)
{
	int			count;
	t_pipeline	*tmp;

	count = 0;
	tmp = pipeline;
	while (tmp)
	{
		count++;
		tmp = tmp->next;
	}
	return (count);
}

int	**make_pipes(int count)
{
	int	**pipes;
	int	i;

	pipes = malloc(sizeof(int *) * (count - 1));
	i = 0;
	while (i < count - 1)
	{
		pipes[i] = malloc(sizeof(int) * 2);
		pipe(pipes[i]);
		i++;
	}
	return (pipes);
}

void	close_all_pipes(int **pipes, int count)
{
	int	i;

	i = 0;
	while (i < count - 1)
	{
		close(pipes[i][0]);
		close(pipes[i][1]);
		free(pipes[i]);
		i++;
	}
	free(pipes);
}

void	return_status(t_var *var, pid_t **pids)
{
	int	i;
	int	status;

	i = 0;
	while (i < var->pipe_count)
	{
		waitpid((*pids)[i], &status, 0);
		if (i == var->pipe_count - 1)
			var->status = WEXITSTATUS(status);
		i++;
	}
}
