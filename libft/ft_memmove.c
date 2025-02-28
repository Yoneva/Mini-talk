/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsbai <amsbai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 22:04:07 by amsbai            #+#    #+#             */
/*   Updated: 2025/02/13 11:39:40 by amsbai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*dest;
	char	*srcc;

	dest = (char *)dst;
	srcc = (char *)src;
	if (src == dst || len == 0)
	{
		return (dst);
	}
	if (srcc > dest)
	{
		return (ft_memcpy(dst, src, len));
	}
	else
	{
		while (len-- > 0)
		{
			dest[len] = srcc[len];
		}
	}
	return (dst);
}

// int main()
// {
// 	char str[] ="1234567890";

// 	ft_memmove(str + 1, str, 9);
// 	printf("%s\n" , str);
// }
