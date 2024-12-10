/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aourhou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 09:50:58 by aourhou           #+#    #+#             */
/*   Updated: 2023/11/08 10:34:11 by aourhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	del(void *s)
{
	free(s);
}

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	t_list	*current;

	current = lst;
	if (!lst || !del)
		return ;
	del(current->content);
	free(current);
}
/*
int	main(void)
{

	t_list *head;
	t_list *s1;
	int i = 0;

	t_list *s2;
	t_list *s3;

	char *v;
	v = (char *)malloc(6 * sizeof(char));
	while (i < 5)
	{
		v[i] = 'h';
		i++;
	}

	v[i] = '\0';

	s1 = (t_list *)malloc(sizeof(t_list));
	s2 = (t_list *)malloc(sizeof(t_list));
	s3 = (t_list *)malloc(sizeof(t_list));

	head = s1;
	s1->next = s2;
	s2->next = s3;
	s3->next = NULL;

	s3->content = v;

	printf("%s",(char *)s3->content);
	ft_lstdelone(head->next->next, del);

	return (0);
}*/
