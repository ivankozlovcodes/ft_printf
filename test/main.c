/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 17:01:28 by ikozlov           #+#    #+#             */
/*   Updated: 2018/03/08 13:54:17 by ikozlov          ###   ########.fr       */
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
	int			tmp;

	n = 10;
	lln = 9223372036854775807;
	llneg = -9223372036854775807;
	printf("===========INFO===========\n");
	printf("Atoi stupid %d\n", ft_atoi("123 %d\n"));
	// printf("wchar_t size is %zu\n", sizeof(wchar_t));
	c = L'诶';
	printf("Wchar (a): %lc\n", c);
	printf("Wchar as char (a): %d: %c\n", c, c);
	int		a = 2147483647;
	void	*pa = (void *)&a;
	// 101111111 11111111 11111111 11111111
	// 110000000 00000000 00000000 00011010
	// printf("Test &a as long long int: %lld\n", *(long long *)pa);
	// ft_printf("Mine: %lld\n", *(long long *)pa);
	// printf("Negative as llx: %llx\n", -2147483648);
	// ft_printf("Mine llx: %llx\n", -2147483648);
	// printf("Negative as lx: %lx\n", -2147483648);
	// ft_printf("Mine lx: %lx\n", -2147483648);
	// printf("Negative as x: %x\n", -2147483648);
	// ft_printf("Mine x: %x\n", -2147483648);
	// // // int wchar = 35830;
	// write(1, &c, 4);
	// // ft_printf("Hello world!\n");
	// // ft_printf("Number: %d\n", n);
	// ft_printf("ll number: %llu\n", lln);
	// ft_printf("ll number octal: %llo\n", lln);
	// ft_printf("ll number octal: %llx\n", lln);
	ft_printf("MINE ===============================\n");
	// ft_printf("ll number: %o\n", n);
	// ft_printf("o number: %llo\n", n);
	// ft_printf("llneg number: %lld\n", llneg);
	// ft_printf("llneg number octal: %llo\n", llneg);
	// ft_printf("llneg number octal: %llx\n", llneg);
	// ft_printf("x number: %x\n", n);
	// ft_printf("X number: %X\n", n);
	// ft_printf("Printable char %c\n", 'a');
	// ft_printf("Printable char %c\n", 'A');
	// ft_printf("Octal over int(o): %o\n", INT32_MAX + 10);
	// ft_printf("Wchar: %d\n", c);
	// ft_printf("Wchar: %lc\n", c);
	// ft_printf("%s\n", "诶");
	// ft_printf("String: %s\n", "asdasdASD");
	// ft_printf("hhd of 128 %hhd\n", 128);
	// ft_printf("precision for 123: %.6d\n", 123);
	// ft_printf("Width for hello: [%10s]\n", "Hello");
	// ft_printf("Width for hello: [%-10s]\n", "Hello");
	// ft_printf("' ' flag |% d|\n", n); 
	// ft_printf("' ' flag |% x|\n", n); 
	// ft_printf("' ' flag for negative |%  d|\n", -n); 
	// ft_printf("'0' flag |%0010x|\n", n); 
	// ft_printf("'0' flag |%0010s|\n", "string"); 
	// ft_printf("'+' flag |%++d|\n", n); 
	// ft_printf("'+' flag |%++hd|\n", n); 
	// ft_printf("padding with '-' flag |%--10d|\n", n); 
	// ft_printf("padding without '-' flag |%10d|\n", n); 
	// ft_printf("Double persent: |%10%|\n", n);
	// ft_printf("'#' flag |%##x|\n", n); 
	// ft_printf("Triple persent: |%%%|\n", n);
	printf("Fixing 42 checker\n ============================\n");
	// ft_printf("%lx\n", 4294967296);
	// ft_printf("%hhX\n", 4294967296);
	// ft_printf("%jx\n", 4294967296);
	// ft_printf("%jx\n", -4294967296);
	// tmp = ft_printf("#x: %#x\n", 42);
	// ft_printf("Adding length for #x with nl case: 9==%d\n", tmp);
	// ft_printf("|    0x2a| == |%#8x|\n", 42);
	ft_printf("%#x\n", 0);
	printf("ORIGINAL\n ============================\n");
	// printf("%d %d %d %d\n", sizeof(long int), sizeof(long), sizeof(long long int), sizeof(long long));
	// printf("Itoa of 922337203854775807: |%s|\n", ft_llitoa_tobase2(922337203854775808, DECIMAL));
	printf("Itoa of 18446744073709551615: |%s|\n", ft_ullitoa_tobase(18446744073709551615, DECIMAL));
	printf("llneg number: %lld\n", llneg);
	printf("llneg number octal: %llo\n", llneg);
	printf("llneg number octal: %llx\n", llneg);
	printf("Octal over int(o): %o\n", INT32_MAX + 10);
	printf("Printable char %c\n", 'a');
	printf("hhx of 17 %hhx\n", (unsigned char)17);
	printf("precision for 123: %.6d\n", 123);
	printf("precision for 123: %.2d\n", 123);
	printf("hhd of 128 %hhd\n", 128);
	printf("pointer %p\n", &n);
	printf("' ' flag |%  d|\n", n); 
	printf("' ' flag |%  x|\n", n); 
	printf("' ' flag for negative |%  d|\n", -n); 
	printf("'0' flag |%0010x|\n", n); 
	printf("'0' flag |%0010s|\n", "string"); 
	printf("'+' flag |%++d|\n", n); 
	printf("'+' flag |%++hd|\n", n); 
	printf("padding with '-' flag |%--10d|\n", n); 
	printf("padding without '-' flag |%10d|\n", n); 
	printf("'#' flag |%##x|\n", n); 
	printf("Double persent: |%10%|\n", n);
	printf("Triple persent: |%%%|\n", n);
	int *p = &n;
	int *p2 = &p;
	ft_printf("%x\n", p2);
	return (0);
}