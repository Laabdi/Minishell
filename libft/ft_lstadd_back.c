/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelomari <aelomari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 20:17:01 by aourhou           #+#    #+#             */
/*   Updated: 2024/05/29 11:00:46 by aelomari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*current;

	current = *lst;
	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	while (current->next != NULL)
		current = current->next;
	current->next = new;
}
/*
int	main(void)
{

	t_list *head;
	t_list *s1;

	t_list *s2;
	t_list *s3;

	char v[] = "hello world";
	s1 = (t_list *)malloc(sizeof(t_list));

	s2 = (t_list *)malloc(sizeof(t_list));
	s3 = (t_list *)malloc(sizeof(t_list));

	head = s1;
	s1->next = s2;
	s2->next = NULL;

	s3->content = v;

	ft_lstadd_back(&head,s3);

	printf("%s",(char *)s2->content);
	return (0);
}*/
