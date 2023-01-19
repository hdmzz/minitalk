/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdamitzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 13:46:37 by hdamitzi          #+#    #+#             */
/*   Updated: 2023/01/19 13:47:56 by hdamitzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	ft_error(int signum)
{
	ft_printf("Cant't send si to pid %d", signum);
	exit(EXIT_FAILURE);
}

void	ft_free(t_list **lst)
{
	t_list	*temp;
	t_list	*curr;

	curr = *lst;
	while (curr)
	{
		temp = curr;
		curr = curr->next;
		free(temp);
	}
	*lst = NULL;
}

void	handler(int signum, siginfo_t *info, void *other)
{
	static int				i;
	static unsigned char	c;
	static t_list			*list = NULL;

	(void)other;
	if (kill(info->si_pid, 0) < 0)
		ft_error(info->si_pid);
	c <<= 1;
	c += (signum == SIGUSR1);
	if ((++i == 8))
	{
		if (c)
			ft_insert(&list, c);
		if (!c)
		{
			kill(info->si_pid, SIGUSR1);
			ft_insert(&list, '\0');
			print_list(list);
			ft_free(&list);
		}
		i = 0;
		c = 0;
	}
	kill(info->si_pid, SIGUSR2);
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
