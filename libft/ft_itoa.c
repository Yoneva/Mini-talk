/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsbai <amsbai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 05:19:05 by amsbai            #+#    #+#             */
/*   Updated: 2024/11/07 23:35:47 by amsbai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	nbrleny(long nbr)
{
	long	length;

	length = 0;
	if (nbr < 0)
	{
		nbr *= -1;
		length += 1;
	}
	if (nbr == 0)
		return (1);
	while (nbr > 0)
	{
		nbr = (nbr / 10);
		length++;
	}
	return (length);
}

static char	*tab_work(char *tab, long nbr, int n)
{
	int	i;

	if (nbr == 0)
	{
		tab[0] = '0';
		return (tab);
	}
	else if (nbr < 0)
	{
		tab[0] = '-';
		nbr *= -1;
	}
	i = n - 1;
	while (nbr > 0)
	{
		tab[i] = (nbr % 10) + '0';
		nbr = (nbr / 10);
		i--;
	}
	return (tab);
}

char	*ft_itoa(int n)
{
	long	nbr;
	int		nbrlen;
	char	*tab;

	nbr = n;
	nbrlen = nbrleny(nbr);
	tab = malloc((nbrlen + 1) * sizeof(char));
	if (!tab)
		return (NULL);
	tab[nbrlen] = '\0';
	return (tab_work(tab, nbr, nbrlen));
}
// int main()
// {
//     printf("%s\n", ft_itoa(0));
// }
