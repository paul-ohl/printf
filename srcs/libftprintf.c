/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pohl <pohl@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 13:28:33 by pohl              #+#    #+#             */
/*   Updated: 2019/11/15 18:33:00 by pohl             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "libftprintf.h"

int		format_length(const char *format)
{
	int			i;

	i = 1;
	while (format[i])
	{
		if (is_in_charset(format[i]))
			return (i);
		else if (format[i] != '-' && format[i] != '.' && format[i] != '*'
				&& (format[i] < '0' || format[i] > '9'))
			return (i - 1);
		i++;
	}
	return (i - 1);
}

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	int			i;
	int			output_len;

	va_start(ap, format);
	i = 0;
	output_len = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] == '%' && (i++) != -1)
			write(1, "%", 1);
		else if (format[i] == '%')
		{
			output_len += arg_printer(format + i + 1, ap);
			i = i + format_length(format + i);
		}
		else
			write(1, &format[i], 1);
		i++;
		output_len++;
	}
	va_end(ap);
	return (output_len);
}
