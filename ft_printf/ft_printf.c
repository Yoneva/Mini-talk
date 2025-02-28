/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsbai <amsbai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 23:15:46 by amsbai            #+#    #+#             */
/*   Updated: 2025/02/27 13:40:45 by amsbai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	if_p(va_list args)
{
	void	*s;

	s = va_arg(args, void *);
	if (s)
		return (ft_putstr("0x") + printaddress((unsigned long)s));
	return (ft_putstr("0x") + ft_putstr("0"));
}

int	conditions(char c, va_list args, t_flags hh)
{
	int		i;

	i = 0;
	if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (c == 'x')
		return (hexamol(va_arg(args, unsigned int), c, i, hh));
	else if (c == 'X')
		return (hexamol(va_arg(args, unsigned int), c, i, hh));
	else if (c == 'i' || c == 'd')
		return (ft_putnbr(va_arg(args, int), c, hh, i));
	else if (c == '%')
		return (ft_putchar('%'));
	else if (c == 'u')
		return (ft_putnbr(va_arg(args, unsigned int), c, hh, i));
	else if (c == 'p')
	{
		return (if_p(args));
	}
	else if (c == 'c')
		return (ft_putchar(va_arg(args, int)));
	else 
		return (ft_putchar(c));
	return (0);
}

t_flags	find_flags(char *c)
{
	int		i;
	t_flags	a;

	i = 0;
	a.hashtag = 0;
	a.plus = 0;
	a.space = 0;
	if (!c)
		return (a);
	while (c[i])
	{
		if (c[i] == ' ')
			a.space = 1;
		else if (c[i] == '+')
			a.plus = 1;
		else if (c[i] == '#')
			a.hashtag = 1;
		else
			break ;
		i++;
	}
	return (a);
}

int	find(int i, const char *s)
{
	while (s[i])
	{
		if (s[i] != ' ' && s[i] != '+' && s[i] != '#')
			break ;
		i++;
	}
	return (i);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		i;
	int		size;
	int		g;
	t_flags	bonus;

	size = 0;
	i = 0;
	g = 0;
	va_start(args, s);
	while (s[i])
	{
		if (s[i] == '%' && s[i + 1])
		{
			i++;
			bonus = find_flags((char *)s + i);
			i = find(i, s);
			size += conditions(s[i], args, bonus);
		}
		else
			size += printcc((char *)s, i);
		i++;
	}
	va_end(args);
	return (size);
}

// int main()
// {
// 	printf("%      %\n");
// 	ft_printf("%      %\n");
// }