/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aourhou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:04:37 by aourhou           #+#    #+#             */
/*   Updated: 2023/11/11 11:35:04 by aourhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
static void	del(void *s)
{
	free(s);
}
*/
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;
	t_list	*hold;

	hold = NULL;
	current = *lst;
	if (!lst || !del)
		return ;
	while (current != NULL)
	{
		del(current->content);
		hold = current->next;
		free(current);
		current = hold;
	}
	*lst = NULL;
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
	ft_lstclear(&head->next, del);
	printf("%s\n",(char *)s2->content);
	printf("%s\n",(char *)s3->content);
	return (0);
}*/
