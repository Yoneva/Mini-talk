/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsbai <amsbai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 00:24:10 by amsbai            #+#    #+#             */
/*   Updated: 2024/10/30 05:41:39 by amsbai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	srclen;
	size_t	dstlen;

	j = 0;
	srclen = ft_strlen(src);
	dstlen = ft_strlen(dst);
	i = dstlen;
	if (dstsize < dstlen || dstsize == dstlen)
	{
		return (dstsize + srclen);
	}
	while (src[j] && j < dstsize - dstlen - 1)
	{
		dst[i] = src[j];
		j++;
		i++;
	}
	dst[i] = '\0';
	return (dstlen + srclen);
}

// int main() {
//     char dst[20] = "Hello";
//     const char *src = " World!";
//     size_t dstsize = sizeof(dst);  // Total buffer size for dst,

//     size_t result = ft_strlcat(dst, src, dstsize);

//     printf("After strlcat: %s\n", dst);
//     printf("Total length of the string tried to create: %zu\n", result);

//     return (0);
// }
