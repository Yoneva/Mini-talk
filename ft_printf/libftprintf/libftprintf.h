/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsbai <amsbai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 21:07:51 by amsbai            #+#    #+#             */
/*   Updated: 2025/02/16 17:46:02 by amsbai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <unistd.h>

typedef struct a_flags{
	int	space;
	int	hashtag;
	int	plus;
}	t_flags;

int	ft_putchar(char c);
int	ft_putnbr(long n, char hexa, t_flags a, int c);
int	ft_putstr(char *s);
int	hexamol(unsigned long n, char c, int a, t_flags hh);
int	printcc(char *s, int i);
int	printaddress(unsigned long n);

#endif