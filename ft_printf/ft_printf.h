/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdamitzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 11:41:49 by hdamitzi          #+#    #+#             */
/*   Updated: 2022/11/30 11:41:52 by hdamitzi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int					ft_printf(const char *s, ...);
unsigned long long	ft_strlen(const char *s);

void				ft_putc(char c, int *total);
void				ft_puts(char *str, int *total);
void				ft_putnb_base(unsigned long long nb,
						char *base, int *total);
void				ft_putnb(unsigned long long nl, int *total);
void				ft_put_ptr(void *ptr, int *total);

#endif
