/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsbai <amsbai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 05:11:41 by amsbai            #+#    #+#             */
/*   Updated: 2024/11/07 23:32:08 by amsbai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	checkdouble(const char *str, char a)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == a)
			return (1);
		i++;
	}
	return (0);
}

static	int	counting_i(char const *s1, char const *set, int i)
{
	while (s1[i])
	{
		if (checkdouble(set, s1[i]) == 1)
			i++;
		else
			break ;
	}
	return (i);
}

static	int	apply_check(char const *s1, char const *set, int s1len)
{
	while (s1len > 0)
	{
		if (checkdouble(set, s1[s1len - 1]) == 1)
			s1len--;
		else
			break ;
	}
	return (s1len);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		s1len;
	char	*str;

	i = 0;
	if (!s1 || !set)
		return (NULL);
	i = counting_i(s1, set, i);
	j = 0;
	s1len = ft_strlen(s1);
	s1len = apply_check(s1, set, s1len);
	if (s1len - i <= 0)
		return (ft_calloc(1, 1));
	str = malloc((s1len - i) + 1);
	if (!str)
		return (NULL);
	while (i < s1len)
	{
		str[j] = s1[i];
		i++;
		j++;
	}
	str[j] = '\0';
	return (str);
}

// #include <stdio.h>

// // int main()
// // {
// //     printf("%s\n", ft_strtrim("amalamalamalamal", "amal"));
// // }
