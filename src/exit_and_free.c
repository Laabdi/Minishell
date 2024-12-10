/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_and_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 18:48:26 by aelomari          #+#    #+#             */
/*   Updated: 2024/11/27 22:47:11 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Minishell.h"

void	free_pipeline(t_pipeline *pipeline)
{
	t_pipeline	*current;
	t_pipeline	*next;

	current = pipeline;
	while (current)
	{
		next = current->next;
		free_words(current->word);
		free(current);
		current = next;
	}
}

void	free_words(t_words *words)
{
	safe_free(&words->cmd);
	free_string_array(&words->args);
	free_infiles_list(&words->infiles);
	free_outfiles_list(&words->outfiles);
	free(words);
}

void	safe_free(char **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

void	free_string_array(char ***array)
{
	int	i;

	i = 0;
	while ((*array)[i])
	{
		safe_free(&(*array)[i]);
		i++;
	}
	free(*array);
	*array = NULL;
}
