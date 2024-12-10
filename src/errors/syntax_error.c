/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 17:11:21 by aelomari          #+#    #+#             */
/*   Updated: 2024/11/28 17:58:14 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/Minishell.h"

void	thisisasynerror(t_syntax_error error)
{
	if (error & ERROR_PIPES)
		ft_putendl_fd(SYNTPIPE, 2);
	else if (error & ERROR_PIPE2)
		ft_putendl_fd(SNTPIPE2, 2);
	else if (error & ERROR_REDIR)
		ft_putendl_fd(REDERROR, 2);
	else if (error & ERROR_REDI2)
		ft_putendl_fd(REDERRO2, 2);
	else if (error & ERROR_HERED)
		ft_putendl_fd(HEREDOCMAXDELIM, 2);
	else if (error & ERROR_MALLOC)
		ft_putendl_fd(MALLOC_FAILED, 2);
}

void	print_error(char *error, char *arg)
{
	if (arg)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(arg, 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(error, 2);
	}
	else
	{
		ft_putstr_fd("minishell: ", 2);
	}
	exit(1);
}
