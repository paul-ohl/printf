/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putunsignedint.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pohl <pohl@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 14:32:07 by pohl              #+#    #+#             */
/*   Updated: 2019/10/25 16:28:46 by pohl             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "libftprintf.h"

int		pf_putunsignedint(va_list ap, const char *format, t_flag flag)
{
	char	c;

	flag.prec = 0;
	format = 0;
	c = va_arg(ap, int);
	write(1, &c, 1);
	return (1);
}
