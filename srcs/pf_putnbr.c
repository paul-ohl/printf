/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pohl <pohl@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 14:33:45 by pohl              #+#    #+#             */
/*   Updated: 2019/11/11 15:30:34 by pohl             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libftprintf.h"

int		count_char_s(int nbr, int precision)
{
	unsigned int	n;
	int				i;

	i = 0;
	if (!nbr)
		return ((precision) ? 1 : 0);
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

void	print_int(int n)
{
	char	buffer[13];
	int		j;
	int		temp;

	if (n > 0)
		n = -n;
	temp = n;
	j = 0;
	if (!temp)
		write(1, "0", 1);
	while (temp < 0 && (j++) != -1)
		temp /= 10;
	buffer[j] = 0;
	while (n < 0)
	{
		j--;
		buffer[j] = -(n % 10) + 48;
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
	int		nbr_char;

	nbr = va_arg(ap, int);
	nbr_char = count_char_s(nbr, flag.prec);
	print_count = nbr_char;
	prec = (flag.prec < 0) ? 0 : flag.prec;
	if (flag.sp_be - (prec + ((nbr < 0) ? 1 : 0)) > 0
			&& flag.sp_be - print_count > 0)
		print_count += put_spaces_before(flag.sp_be, prec, print_count, nbr);
	if (nbr < 0)
		write(1, "-", 1);
	if (flag.prec - nbr_char + ((nbr < 0) ? 1 : 0) > 0)
		print_count += put_zeros(flag.prec + ((nbr < 0) ? 1 : 0), nbr_char);
	else if (flag.zeros - print_count > 0)
		print_count += put_zeros(flag.zeros, print_count);
	if (nbr || flag.prec != 0)
		print_int(nbr);
	if (flag.sp_af - print_count > 0)
		print_count += put_spaces_after(flag.sp_af, print_count);
	return (print_count);
}
