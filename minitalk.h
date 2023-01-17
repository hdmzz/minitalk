/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdamitzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 14:28:48 by hdamitzi          #+#    #+#             */
/*   Updated: 2023/01/17 11:45:29 by hdamitzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include <signal.h>
# include <unistd.h>
# include "ft_printf/ft_printf.h"
# include <stdlib.h>

typedef struct	s_list
{
	unsigned char	c;
	struct s_list	*next;
}				t_list;

void	ft_insert(t_list **list, unsigned char to_add);
void	print_list(t_list *list);
t_list	*ft_initlist(void);
t_list	*ft_lstlast(t_list *list);


#endif
