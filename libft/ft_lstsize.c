/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aourhou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:25:01 by aourhou           #+#    #+#             */
/*   Updated: 2023/11/06 18:49:15 by aourhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	length;

	length = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		length++;
	}
	return (length);
}
/*
int	main(void)
{
	char s[] = "hello";
	char r[] = "world";

	t_list *head;
	t_list *s1;
	t_list *s2;

	s1 = (t_list *) malloc(sizeof(t_list));
	s2 = (t_list *) malloc(sizeof(t_list));

	head = s1;
	s1->next = s2;
	s2->next = NULL;

	printf("%d", ft_lstsize(head));

	return (0);
}*/
