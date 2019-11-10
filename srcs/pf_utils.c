/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pohl <pohl@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 15:32:05 by pohl              #+#    #+#             */
/*   Updated: 2019/10/29 13:19:03 by pohl             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <unistd.h>

int		count_char_hex(unsigned int nbr)
{
	int	i;

	i = 0;
	if (nbr == 0)
		return (1);
	while (nbr > 0)
	{
		nbr /= 16;
		i++;
	}
	return (i);
}

void	itohex(unsigned int n, void (*output)(int*))
{
	int				buffer[13];
	int				j;

	j = count_char_hex(n);
	buffer[j] = -1;
	buffer[j - 1] = 0;
	while (n > 0)
	{
		j--;
		buffer[j] = n % 16;
		n /= 16;
	}
	output(buffer);
}

int		put_spaces_before(int sp_be, int prec, int nbr_len, int nbr)
{
	int		i;
	int		limiter;

	limiter = (prec > nbr_len) ? prec : nbr_len;
	if (nbr < 0 && prec > nbr_len)
		limiter++;
	i = 0;
	while (i < sp_be - limiter)
	{
		write(1, " ", 1);
		i++;
	}
	return (i);
}

int		put_spaces_after(int sp_af, int print_count)
{
	int		i;

	i = 0;
	while (sp_af - print_count > 0)
	{
		write(1, " ", 1);
		print_count++;
		i++;
	}
	return (i);
}

int		put_zeros(int count, int limiter)
{
	int		i;

	i = 0;
	while (i < count - limiter)
	{
		write(1, "0", 1);
		i++;
	}
	return (i);
}
