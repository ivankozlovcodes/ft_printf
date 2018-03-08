/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 16:21:54 by ikozlov           #+#    #+#             */
/*   Updated: 2018/03/07 19:09:25 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_putfmt(void *p, t_finfo *fmt)
{
	char			f;
	char			*s;
	int				m;
	size_t			len;

	f = fmt->format;
	m = fmt->modifier;
	s = NULL;
	if (m == MDF_LL)
		s = ft_llitoa_tobase(*(unsigned long long int *)p, fmt->base);
	// else if (m = MDF_H)
	// {
	// 	if (ft_strchr("diu"))
	// }
	else
	{
		if (f == 'd' || f == 'i')
			s = ft_llitoa(*(int *)p);
		else if (f == 'u')
			s = ft_llitoa(*(unsigned int *)p);
		else if (f == 'o')
			s = ft_llitoa_tobase(*(unsigned long long int *)p, OCTAL);
		else if (f == 'x' || f == 'X')
			s = ft_llitoa_tobase(*(unsigned long long int *)p, f == 'x' ? HEX : HEX_UPPER);
		else if (f == 'c')
		{
			ft_putchar(*(char *)p);
			len = 1;
		}
		else if (f == 'C')
			write(1, p, sizeof(wchar_t));
		else if (f == 's')
			s = (char *)p;
	}
	if (s)
	{
		if ((int)(len = ft_strlen(s)) < fmt->precision)
			s = ft_toprecision(s, fmt->precision - len);
		if (fmt->width && fmt->padding > 0)
			ft_putnchar(' ', fmt->width - len);
		ft_putstr(s);
		if (fmt->width && fmt->padding < 0)
			ft_putnchar(' ', fmt->width - len);
		len = MAX(fmt->width, (int)len);
	}
	return (len);
}

int		to_little_endian(int c)
{
	return (((c >> 24) & 0xff) | ((c << 8) & 0xff0000) |
		((c >> 8) & 0xff00) | ((c << 24) & 0xff000000));
}

int		get_mask(wint_t c, size_t *len)
{
	if (c <= 0x7FF)
	{
		*len = 2;
		return(TWO_BYTES_MASK);
	}
	else if (c <= 0xFFFF)
	{
		*len = 3;
		return (THREE_BYTES_MASK);
	}
	else
	{
		*len = 4;
		return (FOUR_BYTES_MASK);
	}
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
	else
		n = (unsigned int)va_arg(*args, unsigned int);
	return (ft_putfmt((void *)&n, fmt));
}

size_t	print_arg_ptr(va_list *args, t_finfo *fmt)
{
	void	*p;

	if (fmt->modifier == MDF_L && fmt->format == 's')
		fmt->format = 'S';
	// todo: handle unicode strings
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
		// write(1, &n, 4);
	}
	else
		n = (char)va_arg(*args, int);
	return (ft_putfmt((void *)&n, fmt));
}
