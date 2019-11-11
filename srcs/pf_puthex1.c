/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_puthex1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pohl <pohl@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 14:33:23 by pohl              #+#    #+#             */
/*   Updated: 2019/11/10 22:10:43 by pohl             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "libftprintf.h"

int		count_char_ptr(void *ptr, int precision)
{
	int		i;
	long	temp;

	i = 0;
	temp = (long)ptr;
	if (!ptr)
		return ((precision) ? 1 : 0);
	while (temp > 0)
	{
		i++;
		temp /= 16;
	}
	return (i);
}

void	write_result_ptr(int *number)
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

void	ptrtohex(void *ptr)
{
	int				buffer[22];
	long			nbr;
	int				j;

	nbr = (long)ptr;
	j = count_char_ptr(ptr, 42);
	buffer[j] = -1;
	buffer[j - 1] = 0;
	while (nbr > 0)
	{
		j--;
		buffer[j] = nbr % 16;
		nbr /= 16;
	}
	write_result_ptr(buffer);
}

int		pf_puthex1(va_list ap, t_flag flag)
{
	void			*nbr;
	int				prt_count;
	int				prec;

	nbr = va_arg(ap, void *);
	prt_count = count_char_ptr(nbr, flag.prec);
	prec = (flag.prec < 0) ? 0 : flag.prec;
	flag.sp_be -= 2;
	if (flag.sp_be - prec > 0 && flag.sp_be - prt_count > 0)
		prt_count += put_spaces_before(flag.sp_be, prec, prt_count, (int)nbr);
	write(1, "0x", 2);
	prt_count += 2;
	if (flag.prec - count_char_ptr(nbr, flag.prec) > 0)
		prt_count += put_zeros(flag.prec, count_char_ptr(nbr, flag.prec));
	else if (flag.zeros - prt_count > 0)
		prt_count += put_zeros(flag.zeros, prt_count + 1);
	if (nbr || flag.prec != 0)
		ptrtohex(nbr);
	else
		prt_count--;
	if (flag.sp_af - prt_count > 0)
		prt_count += put_spaces_after(flag.sp_af, prt_count + 1);
	return (prt_count);
}
