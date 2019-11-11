/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_puthex2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pohl <pohl@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 14:33:17 by pohl              #+#    #+#             */
/*   Updated: 2019/11/10 22:32:28 by pohl             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "libftprintf.h"

void	write_result_hex2(int *number)
{
	int			i;
	static char	hex_chars[16] = {'0', '1', '2', '3', '4', '5', '6',
			'7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};

	i = 0;
	while (number[i] > -1)
	{
		write(1, &hex_chars[number[i]], 1);
		i++;
	}
}

int		pf_puthex2(va_list ap, t_flag flag)
{
	unsigned int	nbr;
	int				print_count;
	int				prec;

	nbr = va_arg(ap, unsigned int);
	print_count = count_char_hex(nbr, flag.prec);
	prec = (flag.prec < 0) ? 0 : flag.prec;
	if (flag.sp_be - prec > 0 && flag.sp_be - print_count > 0)
		print_count += put_spaces_before(flag.sp_be, prec, print_count, nbr);
	if (flag.prec - count_char_hex(nbr, flag.prec) > 0)
		print_count += put_zeros(flag.prec, count_char_hex(nbr, flag.prec));
	else if (flag.zeros - print_count > 0)
		print_count += put_zeros(flag.zeros, print_count);
	if (nbr || flag.prec != 0)
		itohex(nbr, &write_result_hex2);
	if (flag.sp_af - print_count > 0)
		print_count += put_spaces_after(flag.sp_af, print_count);
	return (print_count);
}
