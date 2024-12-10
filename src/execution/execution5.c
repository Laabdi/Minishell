/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moaregra <moaregra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 22:56:11 by moaregra          #+#    #+#             */
/*   Updated: 2024/12/02 23:00:41 by moaregra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/Minishell.h"

int	is_builtin(t_words *words)
{
	if (ft_strcmp(words->cmd, "echo") == 0)
		return (ft_echo(words->args), 1);
	else if (ft_strcmp(words->cmd, "cd") == 0)
		return (my_cd(words->args, &get_var()->env), 1);
	else if (ft_strcmp(words->cmd, "pwd") == 0)
		return (ft_pwd(), 1);
	else if (ft_strcmp(words->cmd, "export") == 0)
		return (export_to_env(words->args, &get_var()->env), 1);
	else if (ft_strcmp(words->cmd, "unset") == 0)
		return (ft_unset(&get_var()->env, words->args), 1);
	else if (ft_strcmp(words->cmd, "env") == 0)
		return (ft_env(), 1);
	else if (ft_strcmp(words->cmd, "exit") == 0)
		return (ft_exit(words->args), 1);
	return (0);
}

bool	handle_single_builtin(t_pipeline *pipeline)
{
	if (ft_strcmp(pipeline->word->cmd, "exit") == 0
		|| ft_strcmp(pipeline->word->cmd, "cd") == 0
		|| ft_strcmp(pipeline->word->cmd, "export") == 0
		|| ft_strcmp(pipeline->word->cmd, "unset") == 0)
	{
		is_builtin(pipeline->word);
		return (true);
	}
	return (false);
}

void	setup_child_pipes(t_pipeline *pipeline, t_pipe_info *pipe_info)
{
	int	i;

	i = pipe_info->current_index;
	if (i == 0)
	{
		if (pipeline->next)
			dup2(pipe_info->pipes[i][1], STDOUT_FILENO);
	}
	else if (i < pipe_info->pipe_count - 1)
	{
		dup2(pipe_info->pipes[i - 1][0], STDIN_FILENO);
		dup2(pipe_info->pipes[i][1], STDOUT_FILENO);
	}
	else if (i == pipe_info->pipe_count - 1 && pipeline->prev)
	{
		dup2(pipe_info->pipes[i - 1][0], STDIN_FILENO);
	}
}

char	*create_env_str(char *name, char *value)
{
	int		len;
	char	*str;

	len = ft_strlen(name) + ft_strlen(value) + 2;
	str = malloc(sizeof(char) * len);
	if (!str)
		return (NULL);
	ft_strlcpy(str, name, len);
	ft_strlcat(str, "=", len);
	ft_strlcat(str, value, len);
	return (str);
}

char	**env_to_array(t_env *envp)
{
	t_env	*current;
	char	**arr;
	int		size;
	int		i;

	size = list_size(&envp);
	arr = malloc(sizeof(char *) * (size + 1));
	if (!arr)
		return (NULL);
	current = envp;
	i = 0;
	while (current)
	{
		arr[i] = create_env_str(current->name, current->value);
		current = current->next;
		i++;
	}
	arr[i] = NULL;
	return (arr);
}
