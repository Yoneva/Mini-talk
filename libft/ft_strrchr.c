/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsbai <amsbai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 22:09:24 by amsbai            #+#    #+#             */
/*   Updated: 2024/11/05 16:05:35 by amsbai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	slen;

	slen = ft_strlen(s);
	while (1)
	{
		if (s[slen] == (char)c)
		{
			return ((char *)s + slen);
		}
		if (slen == 0)
			break ;
		slen--;
	}
	return (NULL);
}
