/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putflags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pohl <pohl@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 15:32:05 by pohl              #+#    #+#             */
/*   Updated: 2019/10/27 12:57:14 by pohl             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <unistd.h>

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
