/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moaregra <moaregra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 22:59:56 by moaregra          #+#    #+#             */
/*   Updated: 2024/12/02 23:00:22 by moaregra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/Minishell.h"

int	darr_count(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

char	*handle_path_error(char *cmd)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(cmd, 2);
	perror(" ");
	return (NULL);
}

char	*handle_special_cmd_error(char *cmd)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(cmd, 2);
	if (ft_strcmp(cmd, ".") == 0)
		ft_putstr_fd(": filename argument required\n", 2);
	else
		ft_putstr_fd(": command not found\n", 2);
	return (NULL);
}

char	*search_cmd_in_paths(char *cmd, char **paths)
{
	char	*tmp;
	char	*full_path;
	int		i;

	i = 0;
	while (paths[i])
	{
		tmp = ft_strjoin(paths[i], "/");
		full_path = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(full_path, F_OK) == 0)
			return (full_path);
		free(full_path);
		i++;
	}
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd(": command not found\n", 2);
	return (NULL);
}

char	*get_cmd(char *cmd)
{
	char	**paths;
	char	*full_path;

	if (!cmd)
		exit(0);
	if ((cmd[0] == '/' || cmd[0] == '.') && !(ft_strcmp(cmd, ".") == 0
			|| ft_strcmp(cmd, "..") == 0))
	{
		if (access(cmd, F_OK | X_OK) == 0)
			return (ft_strdup(cmd));
		return (handle_path_error(cmd));
	}
	if (ft_strcmp(cmd, ".") == 0 || ft_strcmp(cmd, "..") == 0)
		return (handle_special_cmd_error(cmd));
	paths = ft_split(my_getenv("PATH"), ':');
	if (!paths)
		return (handle_path_error(cmd));
	full_path = search_cmd_in_paths(cmd, paths);
	free_string_array(&paths);
	return (full_path);
}
