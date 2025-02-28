/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsbai <amsbai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 21:20:16 by amsbai            #+#    #+#             */
/*   Updated: 2024/11/06 19:42:11 by amsbai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*freeing(char **arr)
{
	size_t	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
}

static char	**count_malloc(char const *str, char sep)
{
	int		i;
	int		count;
	char	**arr;
	int		flag;

	i = 0;
	flag = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == sep)
			flag = 0;
		else if (flag == 0)
		{
			flag = 1;
			count++;
		}
		i++;
	}
	arr = malloc((count + 1) * sizeof(char *));
	if (arr)
		arr[count] = 0;
	return (arr);
}

static char	*ktb(char const **s, char c )
{
	int		len;
	int		j;
	char	*str;

	j = 0;
	len = 0;
	while ((*s)[len] && (*s)[len] != c)
		len++;
	str = malloc(len + 1);
	if (str)
	{
		str[len] = 0;
		while (j < len)
		{
			str[j] = (*s)[j];
			j++;
		}
		*s += len;
	}
	return (str);
}

char	**ft_split(char const *s, char c)
{
	int		j;
	char	**arr;

	if (!s)
		return (NULL);
	arr = count_malloc(s, c);
	if (!arr)
		return (NULL);
	j = 0;
	while (*s)
	{
		if (*s != c)
		{
			arr[j] = ktb(&s, c);
			if (!arr[j++])
				return (freeing(arr));
		}
		else
			s++;
	}
	return (arr);
}

// int main()
// {
// 	int i = 0;
// 	char *str = "hello!";
// 	char **arr = ft_split(str,' ');
// 	while (arr[i] != 0)
// 	{
// 		printf("%s\n", arr[i]);
// 		i++;
// 	}
// }
