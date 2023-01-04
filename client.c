/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdamitzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 12:05:39 by hdamitzi          #+#    #+#             */
/*   Updated: 2023/01/04 15:35:22 by hdamitzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

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

	i = 128;//0100 0000
			//0110 0111
	while (i)
	{
		if (c & i)
			kill(pid, SIGUSR1);
		else if ((c & i) == 0)
			kill(pid, SIGUSR2);
		i >>= 1;
		usleep(500);
	}
}


int	main(int ac, char **av)
{
	int		i;
	pid_t	pid;

	(void)ac;
	i = 0;
	pid = ft_atoi(av[1]);
	/* if (ac != 3)
	{
		write(1, "client takes 3 args",20);
		exit(EXIT_FAILURE);
	} */
	ft_sender(pid, 'g');
	/* while (av[2][i])
	{
		ft_sender(pid, av[2][i]);
		i++;
	} */
}
