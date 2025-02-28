/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsbai <amsbai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 21:35:36 by amsbai            #+#    #+#             */
/*   Updated: 2024/11/06 18:42:24 by amsbai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*srcc;
	char	*dstt;
	size_t	i;

	i = 0;
	if (dst == src)
		return (dst);
	srcc = (char *)src;
	dstt = (char *)dst;
	while (i < n)
	{
		dstt[i] = srcc[i];
		i++;
	}
	return (dst);
}

// int main()
// {
// 	char str[] ="1234567890";

// 	ft_memcpy(str + 1, str, 9);
// 	printf("%s\n" , str);
// }
