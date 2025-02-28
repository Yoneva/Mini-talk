/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsbai <amsbai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 02:51:52 by amsbai            #+#    #+#             */
/*   Updated: 2024/11/07 23:28:12 by amsbai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	s1len;
	size_t	s2len;

	if (!s1 || !s2)
		return (NULL);
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	str = malloc(s1len + s2len + 1);
	if (!str)
	{
		return (NULL);
	}
	ft_strlcpy(str, s1, (s1len + s2len + 1));
	ft_strlcat(str, s2, (s1len + s2len + 1));
	return (str);
}
// int	main(void)
// {
// 	printf("%s\n", ft_strjoin(NULL, "reda"));
// }
