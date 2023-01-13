/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdamitzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 12:05:32 by hdamitzi          #+#    #+#             */
/*   Updated: 2023/01/12 09:51:07 by hdamitzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>



void	handler(int signum, siginfo_t *info, void *other)
{
	static int				i;
	static unsigned char	c;

	(void)other;
	c <<= 1;
	c += (signum == SIGUSR1);
	if ((++i == 8) && c)
	{
		write(1, &c, 1);
		if (c == '\n')
			kill(info->si_pid, SIGUSR1);
		i = 0;
		c = 0;
	}
}

int	main(void)
{
	struct sigaction	action;
	int					pid;

	pid = getpid();
	action.sa_flags = SA_SIGINFO | SA_RESTART | SA_NODEFER;
	sigemptyset(&action.sa_mask);
	action.sa_sigaction = handler;
	ft_printf("PID : %d\n", pid);
	sigaction(SIGUSR2, &action, NULL);
	sigaction(SIGUSR1, &action, NULL);
	while (1)
		pause();
}
