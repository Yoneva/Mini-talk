/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsbai <amsbai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 18:37:25 by amsbai            #+#    #+#             */
/*   Updated: 2025/02/25 13:29:13 by amsbai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Mini_talk.h"

//Open another terminal and run ps ax  | grep foo
// where foo is the name of the unresponsive program.
void	char_bits(char *str, int PID)
{
	static int	bits;
	int			i;

	i = 0;
	while (str[i])
	{
		bits = 7;
		while (bits >= 0)
		{
			if ((str[i] >> bits) & 1)
				kill(PID, SIGUSR1);
			else
				kill(PID, SIGUSR2);
			usleep(90);
			bits--;
		}
		i++;
	}
}

int	main(int ac, char **argv)
{
	int	pid;
	int	i;

	if (ac != 3)
	{
		write(1, "Not enough arguments, Try again :b\n", 36);
		return (1);
	}
	i = 0;
	pid = ft_atoi(argv[1]);
	char_bits(argv[2], pid);
}
