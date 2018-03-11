/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 21:03:03 by ikozlov           #+#    #+#             */
/*   Updated: 2018/03/10 18:08:05 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	apply_flags(t_finfo *fmt, char *output, size_t output_len)
{
	if ((fmt->format == 'd' || fmt->format == 'i') && !fmt->prefix[0])
	{
		if (has_flag(fmt, '+'))
			fmt->prefix = "+";
		else if (has_flag(fmt, ' '))
			fmt->width = MAX(fmt->width, (int)output_len + 1);
	}
	if (has_flag(fmt, '-'))
		fmt->padding = -1;
	if (has_flag(fmt, '-') || !has_flag(fmt, '0')
		|| ((ft_strchr("di", fmt->format) && fmt->precision != -1)))
		fmt->padding_char = ' ';
	else
		fmt->padding_char = '0';
	if (has_flag(fmt, '#') && ((*output != '0' && fmt->precision != 0) //for "%#x", 0 => |0|
		|| (fmt->format == 'o')))// for "%#.o", 0 = |0|
	{
		if (fmt->format == 'x')
			fmt->prefix = "0x";
		if (fmt->format == 'X')
			fmt->prefix = "0X";
		if (fmt->format == 'o')
			fmt->prefix = "0";
	}
	if (fmt->format == 'p')
		fmt->prefix = "0x";
}

void	apply_precision(t_finfo *fmt, char **output, size_t *len)
{
	int		p;
	int		printed;

	p = fmt->precision;
	printed = 0;
	if (p == -1)
		return ;
	if (p == 0) //for  "|%#.x %#.0x|", 0, 0 = | |
	{
		(*output)[p] = '\0';
		*len = 0;
	}
	if (ft_strchr("diouxX", fmt->format) && (int)*len < p)
	{
		if (**output == '-')
		{
			ft_putchar(**output);
			(*output)++;
			printed = 1;
		}
		ft_putnchar('0', p - *len + printed);
		*len = p + printed;
	}
	else if (ft_strchr("sS", fmt->format) && (int)*len > p)
	{
		(*output)[p] = '\0';
		*len = p;
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

	if (!s && ft_strchr("sS", fmt->format))
		s = "(null)";
	len = ft_strlen(s);
	apply_precision(fmt, &s, &len);
	apply_flags(fmt, s, len);
	len += ft_strlen(fmt->prefix);
	if (fmt->padding_char == '0')
	{
		if (*s == '-')
			ft_putchar(*s++);
		ft_putstr(fmt->prefix);
	}
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

// size_t	ft_putfmthex(t_finfo *fmt, char *s)
// {
// 	return (0);
// }

size_t	ft_putfmtnbr(t_finfo *fmt, char *s)
{
	size_t	len;
	size_t	p_len;
	int		padding_size;

	if (fmt->precision == 0 && *s == '0')
		*s = '\0';
	if (*s == '-' && s++)
		fmt->prefix = "-";
	len = ft_strlen(s);
	apply_flags(fmt, s, len);
	p_len = ft_strlen(fmt->prefix);
	padding_size = fmt->width - MAX((int)len, fmt->precision) - p_len;
	if (fmt->padding_char == '0')
		ft_putstr(fmt->prefix);
	if (fmt->padding > 0)
		ft_putnchar(fmt->padding_char, padding_size);
	if (fmt->padding_char == ' ')
		ft_putstr(fmt->prefix);
	ft_putnchar('0', fmt->precision - len);
	len = MAX(fmt->precision, (int)len);
	ft_putstr(s);
	if (fmt->padding < 0)
		ft_putnchar(fmt->padding_char, padding_size);
	return (MAX(fmt->width, (int)len + (int)p_len));
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
	else if (f == 'p')
		s = ft_ullitoa_tobase((unsigned long)p, HEX);
	else
	{
		s = ft_llitoa_tobase(*(long long int *)p, fmt->base);
		return (ft_putfmtnbr(fmt, s));
	}
	return (ft_putfmtstr(fmt, s));
}
