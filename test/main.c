/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 17:01:28 by ikozlov           #+#    #+#             */
/*   Updated: 2018/03/07 12:57:40 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

int		main(void)
{
	int	n;
	wchar_t		c;
	long long	lln;
	long long	llneg;

	n = 10;
	lln = 9223372036854775807;
	llneg = -9223372036854775807;
	// printf("===========INFO===========\n");
	// printf("wchar_t size is %zu\n", sizeof(wchar_t));
	c = L'诶';
	printf("Wchar (a): %lc\n", c);
	printf("Wchar as char (a): %d: %c\n", c, c);
	// // int wchar = 35830;
	// write(1, &c, 4);
	// // ft_printf("Hello world!\n");
	// // ft_printf("Number: %d\n", n);
	// ft_printf("ll number: %llu\n", lln);
	// ft_printf("ll number octal: %llo\n", lln);
	// ft_printf("ll number octal: %llx\n", lln);
	ft_printf("MINE ===============================\n");
	// ft_printf("ll number: %o\n", n);
	ft_printf("o number: %llo\n", n);
	ft_printf("llneg number: %lld\n", llneg);
	ft_printf("llneg number octal: %llo\n", llneg);
	ft_printf("llneg number octal: %llx\n", llneg);
	// ft_printf("x number: %x\n", n);
	// ft_printf("X number: %X\n", n);
	// ft_printf("Printable char %c\n", 'a');
	// ft_printf("Printable char %c\n", 'A');
	// ft_printf("Octal over int(o): %o\n", INT32_MAX + 10);
	// ft_printf("Wchar (a): %lc\n", c);
	ft_printf("%s\n", "诶");
	ft_printf("String: %s\n", "asdasdASD");
	printf("ORIGINAL\n ============================\n");
	printf("llneg number: %lld\n", llneg);
	printf("llneg number octal: %llo\n", llneg);
	printf("llneg number octal: %llx\n", llneg);
	printf("Octal over int(o): %o\n", INT32_MAX + 10);
	printf("Printable char %c\n", 'a');
	printf("hhx of 17 %hhx\n", (unsigned char)17);
	return (0);
}