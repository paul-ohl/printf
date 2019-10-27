/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pohl <pohl@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 13:29:57 by pohl              #+#    #+#             */
/*   Updated: 2019/10/27 17:04:24 by pohl             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libftprintf.h"

// make && clear && gcc -Wall -Wextra -Werror test.c libftprintf.a && ./a.out

int		main(void)
{
	printf(">%%5u>\n");
	printf(">%5u>\n", 42);
	ft_printf(">%5u>\n\n", 42);
	printf(">%%5u>\n");
	printf(">%5u>\n", -42);
	ft_printf(">%5u>\n\n", -42);
	printf(">%%05u>\n");
	printf(">%05u>\n", 42);
	ft_printf(">%05u>\n\n", 42);
	printf(">%%0*u>\n");
	printf(">%0*u>\n", 5, 42);
	ft_printf(">%0*u>\n\n", 5, 42);
	printf(">%%05u>\n");
	printf(">%05u>\n", -42);
	ft_printf(">%05u>\n\n", -42);
	printf(">%%.10u>\n");
	printf(">%.10u>\n", 42);
	ft_printf(">%.10u>\n\n", 42);
	printf(">%%.10u>\n");
	printf(">%.10u>\n", -42);
	ft_printf(">%.10u>\n\n", -42);
	printf(">%%-5u>\n");
	printf(">%-5u>\n", 42);
	ft_printf(">%-5u>\n\n", 42);
	printf(">%%-5u>\n");
	printf(">%-5u>\n", -42);
	ft_printf(">%-5u>\n\n", -42);
	printf(">%%-15.10u>\n");
	printf(">%-15.10u>\n", 42);
	ft_printf(">%-15.10u>\n\n", 42);
	printf(">%%-15.10u>\n");
	printf(">%-15.10u>\n", -42);
	ft_printf(">%-15.10u>\n\n", -42);
	printf(">%%15.10u>\n");
	printf(">%15.10u>\n", 42);
	ft_printf(">%15.10u>\n\n", 42);
	printf(">%%15.10u>\n");
	printf(">%15.10u>\n", -1);
	ft_printf(">%15.10u>\n\n", -1);
	printf(">%%015.10u>\n");
	printf(">%015.10u>\n", 42);
	ft_printf(">%015.10u>\n\n", 42);
	printf(">%%015.10u>\n");
	printf(">%015.10u>\n", -1);
	ft_printf(">%015.10u>\n\n", -1);
	printf(">%%.0d>\n");
	printf(">%.0d>\n", 0);
	ft_printf(">%.0d>\n\n", 0);
}
