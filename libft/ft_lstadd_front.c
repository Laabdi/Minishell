/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aourhou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 14:13:44 by aourhou           #+#    #+#             */
/*   Updated: 2023/11/06 18:22:06 by aourhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}
/*
int	main(void)
{

	t_list *head;
	t_list *s1;
	t_list *s2;
	t_list *s3;
	char st[] = "hello";
	char sh[] = " world0";
	char sk[] = "the ";

	s1 = malloc(sizeof(t_list));
	s2 = malloc(sizeof(t_list));
	s3 = malloc(sizeof(t_list));

	s1->content = st;
	s2->content = sh;
	s3->content = sk;

	head = s1;
	s1->next = s2;
	s2->next = NULL;
	ft_lstadd_front(&head, s3);

	while(head != NULL)
	{
		printf("%s", (char *)head->content);
		head = head->next;

	}
	return (0);
}*/
