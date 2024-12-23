/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelomari <aelomari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 02:06:46 by aelomari          #+#    #+#             */
/*   Updated: 2024/11/30 16:08:53 by aelomari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*ptr;

	ptr = (char *)malloc(ft_strlen(s) + 1);
	if (ptr == NULL)
		return (NULL);
	ft_strlcpy(ptr, s, ft_strlen(s) + 1);
	return (ptr);
}

char	*ft_strndup(const char *src, size_t n)
{
	size_t	i;
	char	*dup;

	i = 0;
	dup = (char *)malloc((n + 1) * sizeof(char));
	if (!dup)
		return (NULL);
	while (i < n && src[i] != '\0')
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
