/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 17:01:28 by ikozlov           #+#    #+#             */
/*   Updated: 2018/03/12 00:00:00 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>
#include <locale.h>

void	info(void)
{
	wchar_t		c;
	printf("===========INFO===========\n");
}

void	basic(void)
{
	int			n;
	wchar_t		c;

	n = 10;
	c = L'诶';
	printf("Basic 42 checker\n ============================\n");
	ft_printf("ll number: %o\n", n);
	ft_printf("o number: %llo\n", n);
	ft_printf("x number: %x\n", n);
	ft_printf("X number: %X\n", n);
	ft_printf("Printable char %c\n", 'a');
	ft_printf("Printable char %c\n", 'A');
	ft_printf("Octal over int(o): %o\n", INT32_MAX + 10);
	ft_printf("Wchar: %d\n", c);
	ft_printf("Wchar: %lc\n", c);
	ft_printf("String: %s\n", "asdasdASD");
	ft_printf("hhd of 128 %hhd\n", 128);
	ft_printf("precision for 123: %.6d\n", 123);
	ft_printf("Width for hello: [%10s]\n", "Hello");
	ft_printf("Width for hello: [%-10s]\n", "Hello");
	ft_printf("' ' flag |% d|\n", n);
	ft_printf("' ' flag |% x|\n", n);
	ft_printf("' ' flag for negative |%  d|\n", -n);
	ft_printf("'0' flag |%0010x|\n", n);
	ft_printf("'0' flag |%0010s|\n", "string");
	ft_printf("'+' flag |%++d|\n", n);
	ft_printf("'+' flag |%++hd|\n", n);
	ft_printf("padding with '-' flag |%--10d|\n", n);
	ft_printf("padding without '-' flag |%10d|\n", n);
	ft_printf("Double persent: |%10%|\n", n);
	ft_printf("'#' flag |%##x|\n", n);
	ft_printf("Triple persent: |%%%|\n", n);
}

void	ftchecker(void)
{
	int		tmp;

	printf("Fixing 42 checker\n ============================\n");
	ft_printf("%lx\n", 4294967296);
	ft_printf("%hhX\n", 4294967296);
	ft_printf("%jx\n", 4294967296);
	ft_printf("%jx\n", -4294967296);
	tmp = ft_printf("#x: %#x\n", 42);
	ft_printf("Adding length for #x with nl case: 9==%d\n", tmp);
	ft_printf("|    0x2a| == |%#8x|\n", 42);
	ft_printf("|0| = |%#x|\n", 0);
	ft_printf("|0x2a    | = |%#-08x|\n", 42);
	ft_printf("@moulitest: %#.x %#.0x\n", 0, 0);
	ft_printf("@moulitest: |%.x %.0x|\n", 0, 0);
	ft_printf("@moulitest: |%5.x %5.0x|\n", 0, 0);
	ft_printf("%d %s \n", NULL, NULL, NULL);
	ft_printf("%d", -1);
	ft_printf("@moulitest: %.10d", -42);
	ft_printf("%10.5d", 4242);
	ft_printf("|%10.5d|\n", -4242);
	ft_printf("%%");
	ft_printf("@moulitest: %#.x %#.0x", 0, 0);
	ft_printf("| 00| = |%03.2d|\n", 0);
	ft_printf("|+0042| = |%0+5d|\n", 42);
	ft_printf("| 42| = |% d|", 42);
	printf("\n");
	ft_printf("|-1| = |%d|", -1);
}

void	moulinette(void)
{
	int localerr;

	printf("Fixing Moulinete\n ============================\n");
	ft_printf("@moulitest: %#.x %#.0x", 0, 0);
	ft_printf("%zO, %zO\n", 0, USHRT_MAX);
	printf("%zO, %zO\n", 0, USHRT_MAX);
	ft_printf("%jO, %jO\n", 0, USHRT_MAX);
	printf("%jO, %jO\n", 0, USHRT_MAX);
	ft_printf("%zD, %zD\n", 0, USHRT_MAX);
	printf("%zD, %zD\n", 0, USHRT_MAX);
	ft_printf("%15.4u\n", 42);
	printf("%15.4u\n", 42);
	ft_printf("{%3*d}\n", 0, 0);
	printf("{%3*d}\n", 0, 0);
	ft_printf("%.d, %.0d\n", 0, 0);
	printf("%.d, %.0d\n", 0, 0);
	ft_printf("{%05.*d}\n", -15, 42);
	printf("{%05.*d}\n", -15, 42);
	ft_printf("%O\n", LONG_MAX);
	printf("%O\n", LONG_MAX);
	ft_printf("%U\n", ULONG_MAX);
	printf("%U\n", ULONG_MAX);
	ft_printf("|.o, .0o| %.o, %.0o\n", 0, 0);
	printf("%.o, %.0o\n", 0, 0);
	ft_printf("%.x, %.0x\n", 0, 0);
	printf("%.x, %.0x\n", 0, 0);
	ft_printf("|#.x, #.0x| %#.x, %#.0x\n", 0, 0);
	printf("%#.x, %#.0x\n", 0, 0);
	ft_printf("%#o\n", 0);
	printf("%#o\n", 0);
	ft_printf("%#.o\n", 0);
	printf("%#.o\n", 0);
	ft_printf("%hhu, %hhu\n", 0, UCHAR_MAX + 42);
	printf("%hhu, %hhu\n", 0, UCHAR_MAX + 42);
	printf("%.*s\n", -1, NULL);
	ft_printf("%.*s\n", -1, "asd");
	ft_printf("%hhD, %hhD\n", 0, USHRT_MAX);
	printf("%hhD, %hhD\n", 0, USHRT_MAX);
	ft_printf("%#O\n", 1);
	printf("%#O\n", 1);
	ft_printf("%#.3o\n", 1);
	printf("%#.3o\n", 1);
	printf("%15.4d\n", -42);
	ft_printf("%15.4d\n", -42);
	ft_printf("{%10R}\n");
	printf("{%10R}\n");
	ft_printf("%\n");
	printf("%\n");
	ft_printf("%.5p\n", 0);
	printf("%.5p\n", 0);
	ft_printf("%#.o\n", 42);
	printf("%#.o\n", 42);
	ft_printf("%#.x\n", 42);
	printf("%#.x\n", 42);
	ft_printf("%#.3o\n", 1);
	printf("%#.3o\n", 1);
	ft_printf("%#.3x\n", 1);
	printf("%#.3x\n", 1);
	ft_printf("{% 03d}\n", 0);
	printf("{% 03d}\n", 0);
	printf("|%|\n");
	localerr = errno;
	printf("errno = %d: %s\n", localerr, strerror(localerr));
	ft_printf("{%}");
	localerr = errno;
	printf("errno = %d: %s\n", localerr, strerror(localerr));
	ft_printf("%zO, %zO\n", 0, USHRT_MAX);
	printf("%zO, %zO\n", 0, USHRT_MAX);
	ft_printf("%jO, %jO\n", 0, USHRT_MAX);
	printf("%jO, %jO\n", 0, USHRT_MAX);
	ft_printf("%zD, %zD\n", 0, USHRT_MAX);
	printf("%zD, %zD\n", 0, USHRT_MAX);
	ft_printf("%15.4u\n", 42);
	printf("%15.4u\n", 42);
	ft_printf("{%3*d}\n", 0, 0);
	printf("{%3*d}\n", 0, 0);
	ft_printf("%.d, %.0d\n", 0, 0);
	printf("%.d, %.0d\n", 0, 0);
	ft_printf("{%05.*d}\n", -15, 42);
	printf("{%05.*d}\n", -15, 42);
	ft_printf("%O\n", LONG_MAX);
	printf("%O\n", LONG_MAX);
	ft_printf("%U\n", ULONG_MAX);
	printf("%U\n", ULONG_MAX);
	ft_printf("|.o, .0o| %.o, %.0o\n", 0, 0);
	printf("%.o, %.0o\n", 0, 0);
	ft_printf("%.x, %.0x\n", 0, 0);
	printf("%.x, %.0x\n", 0, 0);
	ft_printf("|#.x, #.0x| %#.x, %#.0x\n", 0, 0);
	printf("%#.x, %#.0x\n", 0, 0);
	ft_printf("%#o\n", 0);
	printf("%#o\n", 0);
	ft_printf("%#.o\n", 0);
	printf("%#.o\n", 0);
	ft_printf("%hhu, %hhu\n", 0, UCHAR_MAX + 42);
	printf("%hhu, %hhu\n", 0, UCHAR_MAX + 42);
	printf("%.*s\n", -1, NULL);
	ft_printf("%.*s\n", -1, "asd");
	ft_printf("%hhD, %hhD\n", 0, USHRT_MAX);
	printf("%hhD, %hhD\n", 0, USHRT_MAX);
	ft_printf("%#O\n", 1);
	printf("%#O\n", 1);
	ft_printf("%#.3o\n", 1);
	printf("%#.3o\n", 1);
	printf("%15.4d\n", -42);
	ft_printf("%15.4d\n", -42);
	ft_printf("{%10R}\n");
	printf("{%10R}\n");
	ft_printf("%\n");
	printf("%\n");
	ft_printf("%.5p\n", 0);
	printf("%.5p\n", 0);
	ft_printf("%#.o\n", 42);
	printf("%#.o\n", 42);
	ft_printf("%#.x\n", 42);
	printf("%#.x\n", 42);
	ft_printf("%#.3o\n", 1);
	printf("%#.3o\n", 1);
	ft_printf("%#.3x\n", 1);
	printf("%#.3x\n", 1);
	ft_printf("{% 03d}\n", 0);
	printf("{% 03d}\n", 0);
	printf("|%|\n");
	localerr = errno;
	printf("errno = %d: %s\n", localerr, strerror(localerr));
	ft_printf("{%}");
	localerr = errno;
	printf("errno = %d: %s\n", localerr, strerror(localerr));
}

void widechar(void)
{
	wchar_t		c;

	setlocale(LC_ALL, "en_US.UTF-8");
	printf("WIDECHAR\n ============================ \n");
	c = L'诶';
	ft_printf("%lc\n", c);
	ft_printf("%S\n", L"Á±≥");
	printf("%S\n", L"Á±≥");
	ft_printf("%S\n", L"ابتثجحخدذرزسشصضطظعغفقكلمنهوي");
	printf("%ls\n", L"ابتثجحخدذرزسشصضطظعغفقكلمنهوي");
	printf("Errno: %d. Msg: %s\n", errno, strerror(errno));
	if (1 == 2) // have no idea
	{
		ft_printf("%hhS, %hhS\n", 0, L"米米");
		printf("%hhS, %hhS\n", 0, L"米米");
	}
}

void stringprec(void)
{
	ft_printf("%.4s", "42 is the answer");
}

int		main(void)
{
	// widechar();
	stringprec();
	return (0);
}
