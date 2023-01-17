/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdamitzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 12:05:39 by hdamitzi          #+#    #+#             */
/*   Updated: 2023/01/17 15:11:16 by hdamitzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>

int	control = 0;

int	ft_atoi(const char *str)
{
	long long	res;
	int			sign;

	res = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		if (res != (((res * 10) + (*str - 48)) / 10))
			return (((sign + 1) / -2));
		res = res * 10 + (*str - '0');
		str++;
	}
	return (res * sign);
}

void	ft_sender(pid_t pid, char c)
{
	int	i;

	i = 128;
	while (i)
	{
		control = 0;
		if (c & i)
			kill(pid, SIGUSR1);
		else if ((c & i) == 0)
			kill(pid, SIGUSR2);
		i >>= 1;
		while (control != 1)
			usleep(10);
	}
}

void	listener(int signum)
{
	if (signum == SIGUSR2)
		control = 1;
	if (signum == SIGUSR1)
	{
		write(1, "message bien recu\n", 19);
		exit(EXIT_SUCCESS);
	}
}

int	main(int ac, char **av)
{
	int		i;
	pid_t	pid;

	i = 0;
	pid = ft_atoi(av[1]);
	signal(SIGUSR1, &listener);
	signal(SIGUSR2, &listener);
	if (ac != 3)
	{
		write(1, "client takes 3 args", 20);
		exit(EXIT_FAILURE);
	}
	while (av[2][i])
	{
		ft_sender(pid, av[2][i]);
		i++;
	}
	ft_sender(pid, 0);
}
