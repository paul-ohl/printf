/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pohl <pohl@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 12:59:19 by pohl              #+#    #+#             */
/*   Updated: 2019/10/25 16:29:31 by pohl             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "libftprintf.h"

int		pf_putchar(va_list ap, const char *format, t_flag flag)
{
	char	c;

	format = 0;
	flag.prec = 0;
	c = va_arg(ap, int);
	write(1, &c, 1);
	return (1);
}
