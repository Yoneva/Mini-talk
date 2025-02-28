/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsbai <amsbai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 17:34:05 by amsbai            #+#    #+#             */
/*   Updated: 2025/02/27 13:39:40 by amsbai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Mini_talk.h"

int	g_bits = 7;

void	handler(int sig, struct __siginfo *info, void *context)
{
	static int	i;
	static int	last_pid;

	(void)context;
	if (info->si_pid != last_pid)
	{
		last_pid = info->si_pid;
		i = 0;
		g_bits = 7;
	}
	if (sig == SIGUSR1)
		i = (1 << g_bits) | i;
	g_bits--;
	if (g_bits < 0)
	{
		if (i == '\0')
			kill(info->si_pid, SIGUSR1);
		ft_printf("%c", i);
		i = 0;
		g_bits = 7;
	}
}

int	main(void)
{
	struct sigaction	signal;

	signal.sa_sigaction = handler;
	signal.sa_flags = SA_SIGINFO;
	ft_printf("Process Identification : %d\n", getpid());
	sigaction(SIGUSR1, &signal, NULL);
	sigaction(SIGUSR2, &signal, NULL);
	while (1)
	{
		pause();
	}
}
