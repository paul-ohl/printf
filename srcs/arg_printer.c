/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_printer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pohl <pohl@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 12:32:46 by pohl              #+#    #+#             */
/*   Updated: 2019/10/27 14:06:31 by pohl             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libftprintf.h"

#include <stdio.h>

int		is_in_charset(char c)
{
	int			i;
	static char	*charset = "cdipsuxX";

	i = 0;
	while (charset[i] && charset[i] != c)
		i++;
	return (charset[i]);
}

t_flag	clean_flag(t_flag flag)
{
	t_flag new;

	new = flag;
	if (new.sp_af == 0)
		new.sp_af = (new.sp_be > new.zeros) ? new.sp_be : new.zeros;
	if (new.sp_af > 0)
	{
		new.sp_be = -1;
		new.zeros = -1;
	}
	if (new.prec > -1 && new.zeros > -1)
		new.sp_be = new.zeros;
	return (new);
}

int		select_printer(char function, va_list ap, const char *format,
			t_flag flag)
{
	int		((*ptr[127])(va_list, const char*, t_flag));

	ptr['c'] = &pf_putchar;
	ptr['d'] = &pf_putnbr;
	ptr['i'] = &pf_putnbr;
	ptr['s'] = &pf_putstr;
	ptr['u'] = &pf_putunsignedint;
	ptr['p'] = &pf_puthex1;
	ptr['x'] = &pf_puthex2;
	ptr['X'] = &pf_puthex3;
	return (ptr[(int)function](ap, format, flag));
}

int		arg_printer(const char *format, va_list ap)
{
	int		i;
	t_flag	flag;

	flag.prec = -1;
	flag.sp_af = -1;
	flag.sp_be = -1;
	flag.zeros = -1;
	i = 0;
	while (format[i] && !is_in_charset(format[i]))
	{
		if (format[i] >= '1' && format[i] <= '9')
			flag.sp_be = pf_atoi(format + i, &i, ap);
		else if (format[i] == '0')
			flag.zeros = pf_atoi(format + (++i), &i, ap);
		else if (format[i] == '.')
			flag.prec = pf_atoi(format + (++i), &i, ap);
		else if (format[i] == '-')
			flag.sp_af = pf_atoi(format + (++i), &i, ap);
		else
			i++;
	}
	flag = clean_flag(flag);
	return (select_printer(format[i], ap, format, flag));
}
