/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdamitzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 12:05:32 by hdamitzi          #+#    #+#             */
/*   Updated: 2023/01/07 00:49:38 by hdamitzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include "./ft_printf/ft_printf.h"

void	handler(int signum, siginfo_t *info, void *other)
{
	static int				i;
	static unsigned char	c;

	(void)other;
	(void)info;
	c <<= 1;
	c += (signum == SIGUSR1);
	if ((++i == 8) && c)
	{
		write(1, &c, 1);
		i = 0;
		c = 0;
	}
	if (!c)
		kill(info->si_pid, SIGUSR2);
}

int	main(void)
{
	struct sigaction	action;
	int					pid;

	pid = getpid();
	action.sa_flags = SA_SIGINFO;
	action.sa_sigaction = handler;

	ft_printf("PID : %d\n", pid);
	sigaction(SIGUSR2, &action, NULL);
	sigaction(SIGUSR1, &action, NULL);
	while (1)
		pause();
}
