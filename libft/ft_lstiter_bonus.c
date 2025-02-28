/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsbai <amsbai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 02:00:24 by amsbai            #+#    #+#             */
/*   Updated: 2024/11/06 18:44:16 by amsbai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

// void f(void *p)
// {
// 	char *b;
// 	b =(char *)p;
// 	while (*b)
// 	{
// 			*b = ft_toupper((int)*b);
// 			b++;
// 	}
// }
// #include "ft_lstnew_bonus.c"
// int main()
// {
// 	t_list *node1;
// 	t_list *node2;
// 	t_list *node3;
// 	node1 = ft_lstnew(ft_strdup("asaaa"));
// 	node2 = ft_lstnew(ft_strdup("asadadaaa"));
// 	node3 = ft_lstnew(ft_strdup("asaam/jk/jkja"));
// 	node1->next = node2;
// 	node2->next = node3;
// 	ft_lstiter(node1, f);
// 	printf("%s", node3->content);
// }
