/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aourhou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 18:49:19 by aourhou           #+#    #+#             */
/*   Updated: 2023/11/08 11:12:23 by aourhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft(void *s)
{
	char	*str;

	str = (char *)s;
	*(str + 3) = 'V';
}

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*current;

	if (!lst || !f)
		return ;
	current = lst;
	while (current != NULL)
	{
		f(current->content);
		current = current->next;
	}
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
	char *c;
	v = (char *)malloc(6 * sizeof(char));
	c = (char *)malloc(6 * sizeof(char));
	while (i < 5)
	{
		v[i] = 'h';
		c[i] = 'x';
		i++;
	}

	v[i] = '\0';
	c[i] = '\0';
	s1 = (t_list *)malloc(sizeof(t_list));
	s2 = (t_list *)malloc(sizeof(t_list));
	s3 = (t_list *)malloc(sizeof(t_list));

	head = s1;
	s1->next = s2;
	s2->next = s3;
	s3->next = NULL;
	s2->content = c;
	s3->content = v;

	printf("%s\n",(char *)s2->content);
	printf("%s\n",(char *)s3->content);
	ft_lstiter(head->next, ft);
	printf("%s\n",(char *)s2->content);
	printf("%s\n",(char *)s3->content);
	return (0);
}*/
