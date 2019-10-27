/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pohl <pohl@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 14:33:45 by pohl              #+#    #+#             */
/*   Updated: 2019/10/27 17:08:57 by pohl             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libftprintf.h"

int		count_char_signed(int nbr)
{
	unsigned int	n;
	int				i;

	i = 0;
	if (!nbr)
		return (1);
	if (nbr < 0)
	{
		i++;
		n = -nbr;
	}
	else
		n = nbr;
	while (n > 0)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

void	print_nbr(int n)
{
	char	buffer[13];
	int		j;
	int		temp;

	temp = n;
	j = 0;
	while (temp < 0)
	{
		j++;
		temp /= 10;
	}
	buffer[j] = 0;
	buffer[j - 1] = '0';
	while (n < 0)
	{
		j--;
		buffer[j] = -n % 10 + 48;
		n /= 10;
	}
	j = 0;
	while (buffer[j])
		j++;
	write(1, buffer, j);
}

int		pf_putnbr(va_list ap, t_flag flag)
{
	int		nbr;
	int		print_count;
	int		prec;

	nbr = va_arg(ap, int);
	print_count = count_char_signed(nbr);
	prec = (flag.prec < 0) ? 0 : flag.prec;
	if (flag.sp_be - prec > 0 && flag.sp_be - print_count > 0)
		print_count += put_spaces_before(flag.sp_be, prec, print_count, nbr);
	if (nbr < 0)
		write(1, "-", 1);
	else
		nbr = -nbr;
	if (flag.prec - count_char_signed(nbr) > 0)
		print_count += put_zeros(flag.prec + 1, count_char_signed(nbr));
	else if (flag.zeros - print_count > 0)
		print_count += put_zeros(flag.zeros, print_count);
	if (nbr || flag.prec > 0)
		print_nbr(nbr);
	else
		print_count--;
	if (flag.sp_af - print_count > 0)
		print_count += put_spaces_after(flag.sp_af, print_count);
	return (print_count);
}
