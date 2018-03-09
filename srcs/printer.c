/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 16:21:54 by ikozlov           #+#    #+#             */
/*   Updated: 2018/03/08 13:51:41 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	apply_flags(t_finfo *fmt, char *output, size_t output_len)
{
	if (fmt->format == 'd' || fmt->format == 'i')
	{
		if (has_flag(fmt, '+') && *output != '-')
			ft_putchar('+');
		if (has_flag(fmt, ' '))
			fmt->width = MAX(fmt->width, (int)output_len + 1);
	}
	if (has_flag(fmt, '-'))
		fmt->padding = -1;
	fmt->padding_char = has_flag(fmt, '0') && !has_flag(fmt, '-') ? '0' : ' '; // has_flag('-') for "|%#-08x|" = |0x2a    |
	if (has_flag(fmt, '#') && (*output != '0' || fmt->precision != -1)) // ____ || (//for "%#x", 0 => |0| && //for  "|%#.x %#.0x|", 0, 0 = |0x0 0x0|
	{
		if (fmt->format == 'x')
			fmt->prefix = "0x";
		if (fmt->format == 'X')
			fmt->prefix = "0X";
		if (fmt->format == 'o')
			fmt->prefix = "0";
	}
}

size_t	ft_putfmtc(char c, t_finfo *fmt)
{
	size_t		len;

	len = 1;
	apply_flags(fmt, &c, len);
	if (fmt->padding > 0)
		ft_putnchar(fmt->padding_char, fmt->width - 1);
	ft_putchar(c);
	if (fmt->padding < 0)
		ft_putnchar(fmt->padding_char, fmt->width - 1);
	return (MAX(fmt->width, 1));
}

size_t	ft_putfmtstr(t_finfo *fmt, char *s)
{
	size_t	len;

	if ((int)(len = ft_strlen(s)) < fmt->precision)
		ft_putnchar('0', fmt->precision - len);
	len = MAX(fmt->precision, (int)len);
	apply_flags(fmt, s, len);
	len += ft_strlen(fmt->prefix);
	if (fmt->padding_char == '0')
		ft_putstr(fmt->prefix);
	if (fmt->padding > 0)
		ft_putnchar(fmt->padding_char, fmt->width - len);
	if (fmt->padding_char == ' ')
		ft_putstr(fmt->prefix);
	ft_putstr(s);
	if (fmt->padding < 0)
		ft_putnchar(fmt->padding_char, fmt->width - len);
	len = MAX(fmt->width, (int)len);
	return (len);
}

size_t	ft_putfmt(void *p, t_finfo *fmt)
{
	char			f;
	char			*s;

	f = fmt->format;
	s = NULL;
	if (ft_strchr("ouxX", f))
		s = ft_ullitoa_tobase(*(unsigned long long int *)p, fmt->base);
	else if (f == 'c')
		return (ft_putfmtc(*(char *)p, fmt));
	else if (f == 's')
		s = (char *)p;
	else
		s = ft_llitoa_tobase(*(long long int *)p, fmt->base);
	// if (fmt->modifier == MDF_LL)
	// 	s = ft_llitoa_tobase(*(long long int *)p, fmt->base);
	// else
	// 	if (f == 'd' || f == 'i')
	// 		s = ft_llitoa_tobase(*(int *)p, DECIMAL);
	// 	else if (f == 'u')
	// 		s = ft_ullitoa_tobase(*(unsigned int *)p, DECIMAL);
	// 	else if (ft_strchr("oxX", f))
	// 		s = ft_ullitoa_tobase(*(unsigned long long int *)p, fmt->base);
	// 	else if (f == 'c')
	// 		return (ft_putfmtc(*(char *)p, fmt));
	// 	else if (f == 's')
	// 		s = (char *)p;
	return (ft_putfmtstr(fmt, s));
}

size_t	ft_print_wchar(wint_t c)
{
	int		output;
	size_t	len;

	output = FOUR_BYTES_MASK;
	if (c <= 0x7F)
	{
		output = c & 127;
		len = 1;
	}
	else
	{
		output = get_mask(c, &len);
		output |= (((c >> 6) & 0x3F) << 8) | (c & 0x3F);
		if (c > 0x7FF)
			output |= (((c >> 12) & 0xF) << 16);
		if (c > 0xFFFF)
			output |= (((c >> 18) & 0x7) << 24);
	}
	output = to_little_endian(output);
	write(1, &output, 4);
	return (len);
}

size_t	print_arg_int(va_list *args, t_finfo *fmt)
{
	int				m;
	long long int	n;

	m = fmt->modifier;
	fmt->base = DECIMAL;
	if (m == MDF_LL)
		n = (long long)va_arg(*args, long long int);
	else if (m == MDF_H)
		n = (short)va_arg(*args, int);
	else if (m == MDF_HH)
		n = (signed char)va_arg(*args, int);
	else if (m == MDF_J)
		n = va_arg(*args, intmax_t);
	else if (m == MDF_Z)
		n = va_arg(*args, size_t);
	else
		n = (int)va_arg(*args, int);
	return (ft_putfmt((void *)&n, fmt));
}

size_t	print_arg_uint(va_list *args, t_finfo *fmt)
{
	unsigned long long int	n;

	fmt->base = DECIMAL;
	if (fmt->format == 'o')
		fmt->base = OCTAL;
	else if (fmt->format == 'x')
		fmt->base = HEX;
	else if (fmt->format == 'X')
		fmt->base = HEX_UPPER;
	if (fmt->modifier == MDF_LL)
		n = (unsigned long long)va_arg(*args, unsigned long long int);
	else if (fmt->modifier == MDF_L)
		n = va_arg(*args, unsigned long int);
	else if (fmt->modifier == MDF_J)
		n = va_arg(*args, uintmax_t);
	else if (fmt->modifier == MDF_Z)
		n = va_arg(*args, ssize_t);
	else
		n = (unsigned int)va_arg(*args, unsigned int);
	return (ft_putfmt((void *)&n, fmt));
}

size_t	print_arg_ptr(va_list *args, t_finfo *fmt)
{
	void	*p;

	if (fmt->modifier == MDF_L && fmt->format == 's')
		fmt->format = 'S';
	p = va_arg(*args, void *);
	return (ft_putfmt(p, fmt));
}

size_t	print_arg_char(va_list *args, t_finfo *fmt)
{
	wint_t		n;
	char		f;
	int			m;

	m = fmt->modifier;
	f = fmt->format;
	if (m == MDF_L)
		f = 'C';
	if (f == 'C')
	{
		n = (wint_t)va_arg(*args, wint_t);
		return (ft_print_wchar(n));
	}
	else
		n = (char)va_arg(*args, int);
	return (ft_putfmt((void *)&n, fmt));
}
