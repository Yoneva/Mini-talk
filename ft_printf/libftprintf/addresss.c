/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addresss.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsbai <amsbai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 20:03:13 by amsbai            #+#    #+#             */
/*   Updated: 2024/11/26 00:34:47 by amsbai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	printaddress(unsigned long n)
{
	int		size;
	char	*str;

	size = 0;
	str = "0123456789abcdef";
	if (n >= 16)
		size += printaddress(n / 16);
	size += ft_putchar(str[n % 16]);
	return (size);
}
