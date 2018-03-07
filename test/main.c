/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 17:01:28 by ikozlov           #+#    #+#             */
/*   Updated: 2018/03/06 21:59:47 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

int		main(void)
{
	int	n;
	wchar_t		c;
	long long	lln;

	n = 10;
	lln = 9223372036854775807;
	printf("===========INFO===========\n");
	printf("wchar_t size is %zu\n", sizeof(wchar_t));
	c = L'诶';
	printf("Wchar (a): %lc\n", c);
	printf("Wchar as char (a): %d: %c\n", c, c);
	// ft_printf("Hello world!\n");
	// ft_printf("Number: %d\n", n);
	// ft_printf("ll number: %lld\n", lln);
	ft_printf("ll number: %o\n", n);
	ft_printf("o number: %llo\n", n);
	ft_printf("x number: %x\n", n);
	ft_printf("X number: %X\n", n);
	ft_printf("Printable char %c\n", 'a');
	ft_printf("Printable char %c\n", 'A');
	ft_printf("Octal over int(o): %o\n", INT32_MAX + 10);
	printf("ORIGINAL\n ============================\n");
	printf("Octal over int(o): %o\n", INT32_MAX + 10);
	printf("Printable char %c\n", 'a');
	return (0);
}