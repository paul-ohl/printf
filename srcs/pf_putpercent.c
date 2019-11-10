/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putpercent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pohl <pohl@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 15:39:02 by pohl              #+#    #+#             */
/*   Updated: 2019/11/10 16:03:46 by pohl             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <unistd.h>

int		pf_putpercent(va_list ap, t_flag flag)
{
	int		print_count;

	ap = 0;
	print_count = 1;
	if (flag.sp_be - print_count > 0)
		print_count += put_spaces_before(flag.sp_be, -1, print_count, 1);
	if (flag.zeros - print_count > 0)
		print_count += put_zeros(flag.zeros, print_count);
	write(1, "%", 1);
	if (flag.sp_af - print_count > 0)
		print_count += put_spaces_after(flag.sp_af, print_count);
	return (print_count);
}
