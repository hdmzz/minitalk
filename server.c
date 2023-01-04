/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdamitzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 12:05:32 by hdamitzi          #+#    #+#             */
/*   Updated: 2023/01/04 16:28:20 by hdamitzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include "./ft_printf/ft_printf.h"

void	handler(int signum)
{
	static int				i;
	static unsigned char	c;

	c <<= 1;
	c = c + (signum == SIGUSR1);
	if (++i == 8)
	{
		write(1, &c, 1);
		i = 0;
		c = 0;
	}

}

int	main(void)
{
	struct sigaction	action;
	int					pid;

	pid = getpid();
	action.sa_handler = handler;
	ft_printf("PID : %d\n", pid);
	while (1)
	{
		sigaction(SIGUSR2, &action, NULL);
		sigaction(SIGUSR1, &action, NULL);
		pause();
	}
}
