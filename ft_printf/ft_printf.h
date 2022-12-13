/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rehernan <rehernan@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 18:15:30 by rehernan          #+#    #+#             */
/*   Updated: 2022/05/31 18:42:50 by rehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft/libft.h"
# include <unistd.h>
# include <stdarg.h>

void	ft_put_unsigned_nbr(unsigned int i, int fd);
int		ft_print_unsigned(int d);
int		ft_num_len(unsigned long num, int base);
int		ft_printf_char(int c);
int		ft_print_addr(unsigned long addr);
int		ft_print_hex(unsigned long hex, const char format);
int		ft_print_out(char *s);
int		ft_print_digit(int d);
int		ft_printf(const char *format, ...);

#endif