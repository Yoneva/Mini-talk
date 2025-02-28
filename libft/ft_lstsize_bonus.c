/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsbai <amsbai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 01:45:06 by amsbai            #+#    #+#             */
/*   Updated: 2024/11/07 23:40:48 by amsbai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	counter;

	counter = 0;
	while (lst)
	{
		counter++;
		lst = lst->next;
	}
	return (counter);
}

// int main()
// {
// 	t_list node1;
// 	t_list node2;
// 	t_list node3;

// 	node1.content = "t";
// 	node2.content = "t";
// 	node3.content = "t";
// 	node1.next = &node2;
// 	node2.next = &node3;
// 	node3.next = NULL;

// 	int i = ft_lstsize(&node1);
// 	printf("%d",i);
// }
