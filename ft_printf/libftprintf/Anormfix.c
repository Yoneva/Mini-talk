/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Anormfix.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsbai <amsbai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 00:50:42 by amsbai            #+#    #+#             */
/*   Updated: 2024/11/25 01:09:43 by amsbai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	printcc(char *s, int i)
{
	int	size;

	size = 0;
	if (s[i] == '%')
		return (size);
	else
		size += write(1, &s[i], 1);
	return (size);
}
