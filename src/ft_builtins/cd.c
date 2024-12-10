/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: moaregra <moaregra@student.42.fr>          +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2024/11/27 10:19:47 by moaregra          #+#    #+#             */
/*   Updated: 2024/11/27 10:19:47 by moaregra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/Minishell.h"

static void	error_msg(char	*path)
{
	ft_putstr_fd("cd: no such file or directory: ", 2);
	ft_putstr_fd(path, 2);
	ft_putstr_fd("\n", 2);
}

void	my_cd(char **av, t_env **env)
{
	int		arg_count;
	char	*home;
	char	*path;
	char	*old_path;
	char	*new_path;

	arg_count = darr_count(av);
	if (arg_count > 1)
		return (ft_putstr_fd("cd: too many arguments\n", 2));
	old_path = get_old_path();
	update_old_path(env, old_path);
	if (arg_count == 0)
	{
		home = my_getenv("HOME");
		if (!home)
			return ((void)ft_putstr_fd("cd: HOME not set\n", 2));
		path = home;
	}
	else
		path = av[0];
	if (chdir(path) == -1)
		return (error_msg(path));
	new_path = get_new_path();
	update_new_path(env, new_path);
	return (free(old_path), free(new_path));
}
