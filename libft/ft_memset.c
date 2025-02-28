/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsbai <amsbai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 05:03:15 by amsbai            #+#    #+#             */
/*   Updated: 2024/11/05 23:50:04 by amsbai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*str;
	size_t			i;

	str = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		str[i] = (unsigned char)c;
		i++;
	}
	return (b);
}
// int main()
// {
// 	unsigned int b = 0;
// 	// short c = b;
// 	// ft_memset(&b, 0, 8);
// 	ft_memset(&b, 198, 4);
// 	ft_memset(&b, 142, 3);
// 	ft_memset(&b, 215, 2);
// 	ft_memset(&b, 222, 1);

// 	printf("%u", b);
// }

// 11011110
// 11010111
// 10001110
// 11000110
