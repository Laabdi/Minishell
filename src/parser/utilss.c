/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilss.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelomari <aelomari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 15:04:20 by aelomari          #+#    #+#             */
/*   Updated: 2024/12/02 20:19:18 by aelomari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parsing.h"

void	add_to_array(char ***array, size_t *size, char *element)
{
	char	**new_array;
	size_t	i;

	new_array = ft_malloc((*size + 2) * sizeof(char *));
	if (!new_array)
		return ;
	i = 0;
	while (i < *size)
	{
		new_array[i] = (*array)[i];
		i++;
	}
	if (element)
	{
		new_array[*size] = ft_strdup(element);
		safe_free(&element);
	}
	else
		new_array[*size] = NULL;
	new_array[*size + 1] = NULL;
	free(*array);
	*array = new_array;
	(*size)++;
}

void	add_to_infiles(t_infile **infiles, char *filename, t_red_type type,
		char *delimiter)
{
	t_infile	*new;
	t_infile	*last;

	new = (t_infile *)ft_malloc(sizeof(t_infile));
	new->filename = ft_strdup(filename);
	new->delimiter = delimiter;
	new->type = type;
	new->next = NULL;
	if (!*infiles)
	{
		*infiles = new;
		return ;
	}
	last = *infiles;
	while (last->next)
		last = last->next;
	last->next = new;
}

void	add_to_outfiles(t_outfile **outfiles, char *filename, t_red_type type,
		bool is_amred)
{
	t_outfile	*new;
	t_outfile	*last;

	new = (t_outfile *)ft_malloc(sizeof(t_outfile));
	new->filename = ft_strdup(filename);
	new->ambiguous_red = is_amred;
	new->type = type;
	new->next = NULL;
	if (!*outfiles)
	{
		*outfiles = new;
		return ;
	}
	last = *outfiles;
	while (last->next)
		last = last->next;
	last->next = new;
}
