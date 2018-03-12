/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 21:03:03 by ikozlov           #+#    #+#             */
/*   Updated: 2018/03/11 19:39:02 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
		s = ft_strdup("(null)");
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

size_t	ft_putfmtnbr(t_finfo *fmt, char *s)
{
	size_t	len;
	size_t	p_len;
	int		padding_size;

	len = 0;
	if (*s == '-' && s++)
		fmt->prefix = "-";
	len = ft_strlen(s);
	len += apply_precision_nbr(fmt, s, len);
	len += apply_flags(fmt, s, len);
	p_len = ft_strlen(fmt->prefix);
	padding_size = fmt->width - MAX((int)len, fmt->precision) - p_len;
	if (fmt->padding_char == '0')
		ft_putstr(fmt->prefix);
	if (fmt->padding > 0)
		ft_putnchar(fmt->padding_char, padding_size);
	if (fmt->padding_char == ' ')
		ft_putstr(fmt->prefix);
	ft_putstr(fmt->p_string);
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
	if (ft_strchr("oOuUxX", f))
	{
		s = ft_ullitoa_tobase(*(unsigned long long int *)p, fmt->base);
		return (ft_putfmtnbr(fmt, s));
	}
	else if (f == 'c')
		return (ft_putfmtc(*(char *)p, fmt));
	else if (f == 's')
		s = (char *)p;
	else
	{
		if (f == 'p')
			s = ft_ullitoa_tobase((unsigned long)p, HEX);
		else
			s = ft_llitoa_tobase(*(long long int *)p, fmt->base);
		return (ft_putfmtnbr(fmt, s));
	}
	return (ft_putfmtstr(fmt, s));
}
