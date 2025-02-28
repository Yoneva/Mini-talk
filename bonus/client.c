/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsbai <amsbai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 18:37:25 by amsbai            #+#    #+#             */
/*   Updated: 2025/02/28 10:39:46 by amsbai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Mini_talk.h"

//Open another terminal and run ps ax  | grep foo
// where foo is the name of the unresponsive program.
void	print_message(int sig)
{
	(void)sig;
	ft_printf("Message recieved ✅\n");
}

void	char_bits(unsigned char *str, int pid)
{
	static int	bits;
	int			i;
	int			message_len;

	message_len = ft_strlen((const char *)str);
	i = 0;
	while (i <= message_len)
	{
		bits = 7;
		while (bits >= 0)
		{
			if ((str[i] >> bits) & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(90);
			bits--;
		}
		i++;
	}
}

int	main(int ac, char **argv)
{
	int					pid;
	struct sigaction	sig;
	int					i;

	if (ac != 3)
	{
		write(1, "Not enough arguments, Try again :b\n", 36);
		return (1);
	}
	i = 0;
	sig.sa_handler = print_message;
	pid = ft_atoi(argv[1]);
	sigaction(SIGUSR1, &sig, NULL);
	char_bits((unsigned char *)argv[2], pid);
	return (0);
}
