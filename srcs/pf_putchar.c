/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pohl <pohl@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 12:59:19 by pohl              #+#    #+#             */
/*   Updated: 2019/10/28 11:03:31 by pohl             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "libftprintf.h"

int		pf_putchar(va_list ap, t_flag flag)
{
	char	c;
	int		print_count;

	print_count = 1;
	c = (char)va_arg(ap, int);
	if (flag.sp_be - print_count > 0)
		print_count += put_spaces_before(flag.sp_be, -1, print_count, 1);
	if (flag.zeros - print_count > 0)
		print_count += put_zeros(flag.zeros, print_count);
	write(1, &c, 1);
	if (flag.sp_af - print_count > 0)
		print_count += put_spaces_after(flag.sp_af, print_count);
	return (print_count);
}
