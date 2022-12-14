/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putunsignedint.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pohl <pohl@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 14:32:07 by pohl              #+#    #+#             */
/*   Updated: 2019/11/11 16:53:38 by pohl             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "libftprintf.h"

int		count_char_u(unsigned int nbr, int precision)
{
	int	i;

	i = 0;
	if (!nbr && !precision)
		return (0);
	if (!nbr)
		return (1);
	while (nbr > 0)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}

void	print_unsignedint(unsigned int n)
{
	char			buffer[13];
	int				j;
	unsigned int	temp;

	temp = n;
	j = 0;
	while (temp > 0)
	{
		j++;
		temp /= 10;
	}
	if (!n)
		j++;
	buffer[j] = 0;
	buffer[j - 1] = '0';
	while (n > 0)
	{
		j--;
		buffer[j] = n % 10 + 48;
		n /= 10;
	}
	j = 0;
	while (buffer[j])
		j++;
	write(1, buffer, j);
}

int		pf_putunsignedint(va_list ap, t_flag flag)
{
	unsigned int	nbr;
	int				print_count;
	int				prec;

	nbr = va_arg(ap, unsigned int);
	print_count = count_char_u(nbr, flag.prec);
	prec = (flag.prec < 0) ? 0 : flag.prec;
	if (flag.sp_be - prec > 0 && flag.sp_be - print_count > 0)
		print_count += put_spaces_before(flag.sp_be, prec, print_count, nbr);
	if (flag.prec - count_char_u(nbr, flag.prec) > 0)
		print_count += put_zeros(flag.prec, count_char_u(nbr, flag.prec));
	else if (flag.zeros - print_count > 0)
		print_count += put_zeros(flag.zeros, print_count);
	if (nbr || flag.prec != 0)
		print_unsignedint(nbr);
	if (flag.sp_af - print_count > 0)
		print_count += put_spaces_after(flag.sp_af, print_count);
	return (print_count);
}
