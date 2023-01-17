/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdamitzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 09:30:12 by hdamitzi          #+#    #+#             */
/*   Updated: 2023/01/17 13:25:22 by hdamitzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_list	*ft_initlist(void)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->next = NULL;
	return (new);
}

void	print_list(t_list *list)
{
	t_list	*current;

	current = list;
	while (current)
	{
		ft_printf("%c", current->c);
		current = current->next;
	}
	ft_printf("\n");
}

t_list	*ft_lstlast(t_list *list)
{
	t_list	*last;

	last = list;
	while (last->next)
		last = last->next;
	return (last);
}

void	ft_insert(t_list **list, unsigned char to_add)
{
	t_list	*new;
	t_list	*last;

	if (!(*list)->c && !(*list)->next)
	{
		(*list)->c = to_add;
		return ;
	}
	new = malloc(sizeof(t_list));
	last = ft_lstlast(*list);
	if (!new || !last)
		exit(EXIT_FAILURE);
	new->next = NULL;
	new->c = to_add;
	last->next = new;
}
