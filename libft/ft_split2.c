/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 15:51:30 by aelomari          #+#    #+#             */
/*   Updated: 2024/11/27 22:50:30 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	word_count(const char *str)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		if ((!ft_iswhite(str[i])) && ((ft_iswhite(str[i + 1])) || str[i
					+ 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

void	*free_all(char **sp)
{
	int	j;

	j = 0;
	if (sp == NULL)
		return (NULL);
	while (sp[j] != NULL)
	{
		free(sp[j]);
		j++;
	}
	free(sp);
	return (NULL);
}

static void	fill_split(char **split, const char *s)
{
	size_t	i;
	size_t	j;
	size_t	wordlen;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (ft_iswhite(s[i]))
			i++;
		else
		{
			wordlen = 0;
			while (s[i + wordlen] && !ft_iswhite(s[i + wordlen]))
				wordlen++;
			split[j] = malloc(wordlen + 1);
			if (!split[j])
				free_all(split);
			ft_strlcpy(split[j], s + i, wordlen + 1);
			i += wordlen;
			j++;
		}
	}
	split[j] = NULL;
}

char	**ft_split2(char const *s)
{
	char	**split;

	if (!s)
		return (NULL);
	split = malloc((word_count(s) + 1) * sizeof(char *));
	if (split == NULL)
		return (NULL);
	fill_split(split, s);
	return (split);
}
