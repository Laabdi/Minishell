/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aourhou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:49:34 by aourhou           #+#    #+#             */
/*   Updated: 2023/11/08 10:14:39 by aourhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	int	lenght;

	lenght = ft_lstsize(lst);
	while (lenght > 1)
	{
		lst = lst->next;
		lenght--;
	}
	return (lst);
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

	s2->content = v;

	s3 = ft_lstlast(head);
	printf("%s",(char *)s3->content);
	return (0);
}*/
