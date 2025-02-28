/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsbai <amsbai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 22:02:16 by amsbai            #+#    #+#             */
/*   Updated: 2024/11/02 17:18:18 by amsbai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*s01;
	unsigned char	*s02;

	s01 = (unsigned char *)s1;
	s02 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
	{
		return (0);
	}
	while (s01[i] && i < n - 1)
	{
		if (s01[i] != s02[i])
		{
			return (s01[i] - s02[i]);
		}
		i++;
	}
	return (s01[i] - s02[i]);
}
