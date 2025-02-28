/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsbai <amsbai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 21:23:40 by amsbai            #+#    #+#             */
/*   Updated: 2024/11/26 00:31:49 by amsbai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	printflag(t_flags a, long nb, char hexa)
{
	int	size;

	size = 0;
	if (hexa == 'd' || hexa == 'i')
	{
		if (a.space == 1 && a.plus == 1)
		{
			if (nb >= 0)
				size += ft_putchar('+');
		}
		else if (a.plus == 1)
		{
			if (nb >= 0)
				size += ft_putchar('+');
		}
		else if (a.space == 1)
		{
			if (nb >= 0)
				size += ft_putchar(' ');
		}
	}
	return (size);
}

int	ft_putnbr(long n, char hexa, t_flags hh, int a)
{
	int			size;
	static int	i;

	size = 0;
	if (a == 0)
		i = 0;
	if (i == 0)
		size += printflag(hh, n, hexa);
	i = 1;
	if (n < 0)
	{
		size += ft_putchar('-');
		n *= -1;
	}
	if (n > 9)
		size += ft_putnbr(n / 10, hexa, hh, 1);
	size += ft_putchar(n % 10 + 48);
	return (size);
}
