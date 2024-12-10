/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelomari <aelomari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 17:56:40 by aelomari          #+#    #+#             */
/*   Updated: 2024/11/29 17:56:40 by aelomari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/Minishell.h"

t_env	*creat_list(void)
{
	t_env	*first_node;

	first_node = (t_env *)malloc(sizeof(t_env));
	if (!first_node)
		return (NULL);
	first_node->next = NULL;
	return (first_node);
}

t_env	*get_last_node(t_env **lst)
{
	t_env	*tmp;

	if (*lst == NULL)
		return (NULL);
	tmp = *lst;
	while (tmp->next != NULL)
		tmp = tmp->next;
	return (tmp);
}

void	ft_lstadd_backk(t_env **lst, t_env *new)
{
	t_env	*last;

	if (!new)
		return ;
	if (!lst)
		return ;
	if (!*lst)
	{
		*lst = new;
		new->next = NULL;
		return ;
	}
	last = *lst;
	while (last->next)
		last = last->next;
	last->next = new;
	new->next = NULL;
}

void	free_env_list(t_env **env)
{
	t_env	*current;
	t_env	*next;

	if (!env || !*env)
		return ;
	current = *env;
	while (current)
	{
		next = current->next;
		free(current->name);
		free(current->value);
		free(current);
		current = next;
	}
	*env = NULL;
}

int	list_size(t_env **env)
{
	int		i;
	t_env	*tmp;

	i = 0;
	tmp = *env;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}
