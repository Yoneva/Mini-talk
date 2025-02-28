/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsbai <amsbai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 03:27:34 by amsbai            #+#    #+#             */
/*   Updated: 2024/11/05 22:39:25 by amsbai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*node;
	t_list	*head;
	void	*content;

	if (!lst || !f || !del)
		return (NULL);
	head = 0;
	while (lst)
	{
		content = f(lst->content);
		node = ft_lstnew(content);
		if (!node)
		{
			del(content);
			ft_lstclear(&head, del);
			break ;
		}
		ft_lstadd_back(&head, node);
		lst = lst->next;
	}
	return (head);
}

// #include "ft_lstnew_bonus.c"

// int main()
// {
// 	t_list *node1;
// 	t_list node2;
// 	node1 = ft_lstnew("Amal");
// 	node2.content = "hh";
// 	node2.next = NULL;
// 	ft_lstadd_back(&node1, &node2);
// 	printf("%d\n", ft_lstsize(node1));
// }
