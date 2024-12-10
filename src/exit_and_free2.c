/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_and_free2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelomari <aelomari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 15:17:55 by aelomari          #+#    #+#             */
/*   Updated: 2024/11/29 15:17:56 by aelomari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Minishell.h"

void	free_env(t_env **env)
{
	t_env	*current;
	t_env	*next;

	current = *env;
	while (current)
	{
		next = current->next;
		safe_free(&current->name);
		safe_free(&current->value);
		free(current);
		current = next;
	}
	*env = NULL;
}

void	free_infiles_list(t_infile **infile)
{
	t_infile	*current;
	t_infile	*next;

	current = *infile;
	while (current)
	{
		next = current->next;
		free(current->filename);
		free(current->delimiter);
		free(current);
		current = next;
	}
	*infile = NULL;
}

void	free_outfiles_list(t_outfile **s_outfile)
{
	t_outfile	*current;
	t_outfile	*next;

	current = *s_outfile;
	while (current)
	{
		next = current->next;
		safe_free(&current->filename);
		free(current);
		current = next;
	}
	*s_outfile = NULL;
}
