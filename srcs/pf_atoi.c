/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pohl <pohl@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 15:53:47 by pohl              #+#    #+#             */
/*   Updated: 2019/10/27 14:08:28 by pohl             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>

void	increment_i(const char *str, int *i_ptr)
{
	int i;

	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	*i_ptr += i;
}

int		pf_atoi(const char *str, int *i_ptr, va_list ap)
{
	unsigned int	i;
	unsigned long	result;
	int				sign;

	i = 0;
	result = 0;
	sign = 1;
	while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
			|| str[i] == '\r' || str[i] == '\f' || str[i] == '\v'))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (str[i] == '*')
		return (va_arg(ap, int));
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		result *= 10;
		result += str[i] - 48;
		i++;
	}
	increment_i(str, i_ptr);
	return (result * sign);
}
