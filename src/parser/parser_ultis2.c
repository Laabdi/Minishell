/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_ultis2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelomari <aelomari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 15:03:18 by aelomari         #+#    #+#             */
/*   Updated: 2024/11/29 15:04:02 by aelomari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parsing.h"

void	process_word_array(char **word_array)
{
	int	i;

	i = 0;
	if (!word_array)
		return ;
	while (word_array[i])
	{
		between_quote(word_array[i]);
		expand_env_vars(&word_array[i]);
		quoting_str(&word_array[i]);
		i++;
	}
}

t_infile	*create_new_infile_node(t_infile *current)
{
	t_infile	*new_node;

	new_node = malloc(sizeof(t_infile));
	between_quote(current->filename);
	expand_env_vars(&current->filename);
	quoting_str(&current->filename);
	new_node->filename = ft_strdup(current->filename);
	if (current->delimiter)
		new_node->delimiter = ft_strdup(current->delimiter);
	else
		new_node->delimiter = NULL;
	new_node->type = current->type;
	new_node->next = NULL;
	return (new_node);
}

void	append_to_new_list(t_infile **new_list, t_infile **prev_new,
		t_infile *new_node)
{
	if (*prev_new)
		(*prev_new)->next = new_node;
	else
		*new_list = new_node;
	*prev_new = new_node;
}

void	process_word_infiles(t_infile **infiles)
{
	t_infile	*current;
	t_infile	*new_list;
	t_infile	*prev_new;
	t_infile	*new_node;

	current = *infiles;
	new_list = NULL;
	prev_new = NULL;
	while (current)
	{
		new_node = create_new_infile_node(current);
		append_to_new_list(&new_list, &prev_new, new_node);
		current = current->next;
	}
	free_infiles_list(infiles);
	*infiles = new_list;
}

void	process_word_outfiles(t_outfile **outfiles)
{
	t_outfile	*new_list;
	t_outfile	*current;

	new_list = NULL;
	current = *outfiles;
	while (current)
	{
		between_quote(current->filename);
		get_var()->is_ambiguous = FALSE;
		expand_env_vars(&current->filename);
		quoting_str(&current->filename);
		add_to_outfiles(&new_list, current->filename, current->type,
			get_var()->is_ambiguous);
		current = current->next;
	}
	free_outfiles_list(outfiles);
	*outfiles = new_list;
}
