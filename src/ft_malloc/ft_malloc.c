/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelomari <aelomari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 08:10:27 by aelomari          #+#    #+#             */
/*   Updated: 2024/10/13 09:46:39 by aelomari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/Minishell.h"

void	*ft_malloc(size_t size)
{
	char	*result;

	result = ft_calloc(size, 1);
	if (!result)
	{
		thisisasynerror(ERROR_MALLOC);
		exit(1);
	}
	return (result);
}
