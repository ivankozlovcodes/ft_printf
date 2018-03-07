/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 16:21:54 by ikozlov           #+#    #+#             */
/*   Updated: 2018/03/07 12:31:33 by ikozlov          ###   ########.fr       */
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
		ft_putstr(s);
	return (s ? ft_strlen(s) : len);
}

size_t	print_arg_int(va_list *args, t_finfo *fmt)
{
	int				m;
	long long int	n;

	m = fmt->modifier;
	if (m == MDF_LL)
		n = (long long)va_arg(*args, long long int);
	else
		n = (int)va_arg(*args, int);
	return (ft_putfmt((void *)&n, fmt));
}

size_t	print_arg_uint(va_list *args, t_finfo *fmt)
{
	unsigned long long int	n;
	int						m;

	m = fmt->modifier;
	if (m == MDF_LL)
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
		n = (wchar_t)va_arg(*args, wint_t);
	else
		n = (char)va_arg(*args, int);
	return (ft_putfmt((void *)&n, fmt));
}
