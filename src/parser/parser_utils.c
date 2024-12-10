/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelomari <aelomari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 10:59:01 by aelomari          #+#    #+#             */
/*   Updated: 2024/11/30 18:48:50 by aelomari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parsing.h"

void	remove_quotes(t_words *words)
{
	if (words->cmd)
	{
		between_quote(words->cmd);
		expand_env_vars(&words->cmd);
		quoting_str(&words->cmd);
	}
	process_word_array(words->args);
	process_word_infiles(&words->infiles);
	process_word_outfiles(&words->outfiles);
}

t_pipeline	*pipe_addnew(t_words *words)
{
	t_pipeline	*new;

	remove_quotes(words);
	new = (t_pipeline *)ft_malloc(sizeof(t_pipeline));
	if (!new)
		return (NULL);
	new->word = words;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

void	pipe_addback(t_pipeline **pipel, t_pipeline *new)
{
	t_pipeline	*tmp;

	if (!new)
		return ;
	if (!*pipel)
	{
		*pipel = new;
		new->prev = NULL;
		return ;
	}
	tmp = *pipel;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	new->prev = tmp;
}
