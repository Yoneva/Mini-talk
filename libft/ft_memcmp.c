/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsbai <amsbai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 21:52:42 by amsbai            #+#    #+#             */
/*   Updated: 2024/11/05 23:26:22 by amsbai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s01;
	unsigned char	*s02;
	size_t			i;

	i = 0;
	s01 = (unsigned char *)s1;
	s02 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (i < n - 1)
	{
		if (s01[i] != s02[i])
		{
			return (s01[i] - s02[i]);
		}
		i++;
	}
	return (s01[i] - s02[i]);
}
