/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pohl <pohl@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 13:29:57 by pohl              #+#    #+#             */
/*   Updated: 2019/10/28 15:13:16 by pohl             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libftprintf.h"

// make && clear && gcc -Wall -Wextra test.c libftprintf.a && ./a.out

int		main(void)
{
	printf(">%%5X>\n");
	printf(">%5X>\n", 42);
	ft_printf(">%5X>\n\n", 42);
	printf(">%%5X>\n");
	printf(">%5X>\n", -42);
	ft_printf(">%5X>\n\n", -42);
	printf(">%%05X>\n");
	printf(">%05X>\n", 42);
	ft_printf(">%05X>\n\n", 42);
	printf(">%%0*X>\n");
	printf(">%0*X>\n", 5, 42);
	ft_printf(">%0*X>\n\n", 5, 42);
	printf(">%%05X>\n");
	printf(">%05X>\n", -42);
	ft_printf(">%05X>\n\n", -42);
	printf(">%%.10X>\n");
	printf(">%.10X>\n", 42);
	ft_printf(">%.10X>\n\n", 42);
	printf(">%%.10X>\n");
	printf(">%.10X>\n", -42);
	ft_printf(">%.10X>\n\n", -42);
	printf(">%%-5X>\n");
	printf(">%-5X>\n", 42);
	ft_printf(">%-5X>\n\n", 42);
	printf(">%%-5X>\n");
	printf(">%-5X>\n", -42);
	ft_printf(">%-5X>\n\n", -42);
	printf(">%%-15.10X>\n");
	printf(">%-15.10X>\n", 42);
	ft_printf(">%-15.10X>\n\n", 42);
	printf(">%%-15.10X>\n");
	printf(">%-15.10X>\n", 42);
	ft_printf(">%-15.10X>\n\n", 42);
	printf(">%%15.10X>\n");
	printf(">%15.10X>\n", 42);
	ft_printf(">%15.10X>\n\n", 42);
	printf(">%%15.10X>\n");
	printf(">%15.10X>\n", 42);
	ft_printf(">%15.10X>\n\n", 42);
	printf(">%%015.10X>\n");
	printf(">%015.10X>\n", 42);
	ft_printf(">%015.10X>\n\n", 42);
	printf(">%%015.10X>\n");
	printf(">%015.10X>\n", 42);
	ft_printf(">%015.10X>\n\n", 42);
	printf(">%%.0d>\n");
	printf(">%.0d>\n", 0);
	ft_printf(">%.0d>\n\n", 0);
}
