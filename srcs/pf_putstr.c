/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pohl <pohl@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 14:33:37 by pohl              #+#    #+#             */
/*   Updated: 2019/10/27 19:01:07 by pohl             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "libftprintf.h"

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		pf_putstr(va_list ap, t_flag flag)
{
	char	*str;
	int		print_count;
	int		char_num;

	str = va_arg(ap, char*);
	char_num = ft_strlen(str);
	print_count = char_num;
	if (flag.prec < 0)
		flag.prec = char_num;
	if (flag.sp_be - print_count > 0)
		print_count += put_spaces_before(flag.sp_be, -1, print_count, 1);
	if (flag.zeros - print_count > 0)
		print_count += put_zeros(flag.zeros, print_count);
	write(1, str, ((char_num < flag.prec) ? char_num : flag.prec));
	if (flag.sp_af - print_count > 0)
		print_count += put_spaces_after(flag.sp_af, print_count);
	return (print_count);
}
