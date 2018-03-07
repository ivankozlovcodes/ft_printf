/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 17:01:28 by ikozlov           #+#    #+#             */
/*   Updated: 2018/03/06 19:19:50 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

int		main(void)
{
	int	n;
	long long	lln;

	n = 10;
	lln = 9223372036854775807;
	// ft_printf("Hello world!\n");
	// ft_printf("Number: %d\n", n);
	// ft_printf("ll number: %lld\n", lln);
	ft_printf("ll number: %o\n", n);
	ft_printf("o number: %llo\n", n);
	ft_printf("x number: %x\n", n);
	ft_printf("X number: %X\n", n);
	printf("ORIGINAL\n ============================\n");
	printf("Octal over int(o): %o\n", INT32_MAX + 10);
	return (0);
}