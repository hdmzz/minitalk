/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdamitzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 12:05:39 by hdamitzi          #+#    #+#             */
/*   Updated: 2023/01/23 11:54:19 by hdamitzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_control = 0;

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
		if (kill(pid, 0) < 0)
		{
			ft_printf("Can't send to PID %d", pid);
			exit(EXIT_FAILURE);
		}
		g_control = 0;
		if (c & i)
			kill(pid, SIGUSR1);
		else if ((c & i) == 0)
			kill(pid, SIGUSR2);
		i >>= 1;
		while (g_control != 1)
			usleep(10);
	}
}

void	listener(int signum)
{
	if (signum == SIGUSR2)
		g_control = 1;
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

	if (ac != 3)
	{
		write(1, "client takes 3 args", 20);
		exit(EXIT_FAILURE);
	}
	i = 0;
	pid = ft_atoi(av[1]);
	if (!pid || pid < 0)
	{
		ft_printf("PID invalid\n");
		exit(EXIT_FAILURE);
	}
	signal(SIGUSR1, &listener);
	signal(SIGUSR2, &listener);
	while (av[2][i])
	{
		ft_sender(pid, av[2][i]);
		i++;
	}
	ft_sender(pid, 0);
}
