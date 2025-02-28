/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsbai <amsbai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 02:05:33 by amsbai            #+#    #+#             */
/*   Updated: 2024/11/02 17:31:15 by amsbai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}

// int main()
// {
// 	t_list node1;
// 	t_list node2;
// 	node1.content = "amal";
// 	node2.content = "aml";
// 	node1.next = &node2;
// 	node2.next = NULL;
// 	printf("%s\n", ft_lstlast(&node1)->content);
// }