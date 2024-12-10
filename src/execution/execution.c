/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moaregra <moaregra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 16:10:38 by aelomari          #+#    #+#             */
/*   Updated: 2024/12/02 23:49:14 by moaregra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/Minishell.h"

void	execute_child_process(t_var *var, t_pipeline *pipeline,
		t_pipe_info *pipe_info)
{
	char	**cmd;
	char	**env;

	cmd = NULL;
	env = NULL;
	handle_input_redirection(pipeline);
	setup_child_pipes(pipeline, pipe_info);
	handle_output_redirection(pipeline);
	close_all_pipes(pipe_info->pipes, pipe_info->pipe_count);
	if (is_builtin(pipeline->word))
	{
		free_env_list(&var->env);
		free(var->line);
		free_pipeline(var->pipeline);
		free(var->pids);
		free(var);
		exit(0);
	}
	cmd = handle_cmd(pipeline);
	env = env_to_array(var->env);
	execve(cmd[0], cmd, env);
	free_child_resources(var, cmd, env);
	exit(127);
}

static void	wait_for_children(t_var *var, pid_t *pids, int pipe_count)
{
	int	i;
	int	status;

	i = 0;
	while (i < pipe_count)
	{
		waitpid(pids[i], &status, 0);
		if (i == pipe_count - 1)
			if (WIFEXITED(status))
				var->status = WEXITSTATUS(status);
		i++;
	}
}

static t_pipe_info	init_pipe_info(int pipe_count)
{
	t_pipe_info	pipe_info;

	pipe_info.pipe_count = pipe_count;
	pipe_info.pipes = make_pipes(pipe_count);
	pipe_info.current_index = 0;
	return (pipe_info);
}

void	execute(t_var *var)
{
	t_pipeline	*pipeline;
	t_pipe_info	pipe_info;

	pipeline = var->pipeline;
	var->pipe_count = pipe_count(pipeline);
	pipe_info = init_pipe_info(var->pipe_count);
	var->pids = malloc(sizeof(pid_t) * var->pipe_count);
	if (!var->pids)
		return (close_all_pipes(pipe_info.pipes, pipe_info.pipe_count));
	if (var->pipe_count == 1 && handle_single_builtin(pipeline))
		return (free(var->pids), free(pipe_info.pipes));
	while (pipeline)
	{
		var->pids[pipe_info.current_index] = fork();
		if (var->pids[pipe_info.current_index] == 0)
			execute_child_process(var, pipeline, &pipe_info);
		pipeline = pipeline->next;
		pipe_info.current_index++;
	}
	signal(SIGINT, sig_hh);
	signal(SIGQUIT, sig_hhh);
	close_all_pipes(pipe_info.pipes, pipe_info.pipe_count);
	wait_for_children(var, var->pids, pipe_info.pipe_count);
	free(var->pids);
}
