/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdamitzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 13:46:33 by hdamitzi          #+#    #+#             */
/*   Updated: 2023/01/20 11:49:38 by hdamitzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H
# include <signal.h>
# include <unistd.h>
# include "ft_printf/ft_printf.h"
# include <stdlib.h>

typedef struct s_list
{
	unsigned char	c;
	struct s_list	*next;
}				t_list;

void	ft_insert(t_list **list, unsigned char to_add);
void	print_list(t_list *list);
t_list	*ft_initlist(unsigned char to_add);
t_list	*ft_lstlast(t_list *list);

#endif
