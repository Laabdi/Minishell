/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelomari <aelomari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 17:12:24 by aelomari          #+#    #+#             */
/*   Updated: 2024/11/06 18:48:17 by aelomari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/Minishell.h"

void	check_pipes(t_var *var)
{
	char	**to_check;
	int		i;

	i = 0;
	to_check = ft_split2(var->line);
	while (to_check[i])
	{
		if (!ft_strncmp(to_check[i], "|", 1))
		{
			if (!ft_strncmp(to_check[i], "||", 2))
				return ((void)free_all(to_check), thisisasynerror(ERROR_PIPE2),
					(void)(var->synerrflag = TRUE));
			else if (to_check[i + 1] && !ft_strncmp(to_check[i + 1], "|", 1))
				return ((void)free_all(to_check), thisisasynerror(ERROR_PIPES),
					(void)(var->synerrflag = TRUE));
			else if (!ft_strncmp(to_check[i], "|", 1) && i == 0)
				return ((void)free_all(to_check), thisisasynerror(ERROR_PIPES),
					(void)(var->synerrflag = TRUE));
			if (!to_check[i + 1] && !to_check[i][1])
				return ((void)free_all(to_check), thisisasynerror(ERROR_PIPES),
					(void)(var->synerrflag = TRUE));
		}
		i++;
	}
	free_all(to_check);
}
