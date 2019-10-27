/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pohl <pohl@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 13:06:58 by pohl              #+#    #+#             */
/*   Updated: 2019/10/27 17:32:23 by pohl             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H

# define LIBFTPRINTF_H

# include <stdarg.h>

typedef struct	s_flag
{
	int		prec;
	int		sp_be;
	int		sp_af;
	int		zeros;
}				t_flag;

int				ft_printf(const char *format, ...);
int				arg_printer(const char *format, va_list ap);
int				is_in_charset(char c);
int				pf_putchar(va_list ap, t_flag flag);
int				pf_puthex1(va_list ap, t_flag flag);
int				pf_puthex2(va_list ap, t_flag flag);
int				pf_puthex3(va_list ap, t_flag flag);
int				pf_putnbr(va_list ap, t_flag flag);
int				pf_putstr(va_list ap, t_flag flag);
int				pf_putunsignedint(va_list ap, t_flag flag);
int				pf_atoi(const char *str, int *i_ptr, va_list ap);
int				put_spaces_after(int sp_af, int print_count);
int				put_spaces_before(int sp_be, int prec, int nbr_len, int nbr);
int				put_zeros(int count, int limiter);

#endif
