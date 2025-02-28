/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsbai <amsbai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 23:35:19 by amsbai            #+#    #+#             */
/*   Updated: 2024/11/05 16:06:09 by amsbai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (1)
	{
		if (s[i] == (char)c)
		{
			return ((char *)s + i);
		}
		if (s[i] == 0)
			break ;
		i++;
	}
	return (NULL);
}

// #include <stdio.h>
// int main()
// {
// 	printf("%s\n", ft_strchr("teste", '\0'));
// }
