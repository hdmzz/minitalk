/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdamitzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 12:05:32 by hdamitzi          #+#    #+#             */
/*   Updated: 2023/01/03 15:03:06 by hdamitzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include "./ft_printf/ft_printf.h"

void	handler(int signum)
{
	if (signum == SIGUSR1)
		ft_printf("test");
	ft_printf("helllo handler\n");
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
		sigaction(SIGINT, &action, NULL);
		sigaction(SIGUSR1, &action, NULL);
		pause();
	}
}
