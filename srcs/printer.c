/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 16:21:54 by ikozlov           #+#    #+#             */
/*   Updated: 2018/03/06 19:06:12 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_putfmt(void *p, t_finfo *fmt)
{
	char			f;
	char			*s;
	int				m;

	f = fmt->format;
	m = fmt->modifier;
	if (m == MDF_LL)
	{
		if (f == 'd' || f == 'i')
			s = ft_llitoa(*(long long int *)p);
		else if (f == 'u')
			s = ft_llitoa(*(unsigned long long int *)p);
		else if (f == 'o')
			s = ft_llitoa_tobase(*(unsigned long long int *)p, OCTAL);
	}
	else
	{
		if (f == 'd' || f == 'i')
			s = ft_llitoa(*(int *)p);
		else if (f == 'u')
			s = ft_llitoa(*(unsigned int *)p);
		else if (f == 'o')
			s = ft_llitoa_tobase(*(unsigned long long int *)p, OCTAL);
	}
	ft_putstr(s);
	return (ft_strlen(s));
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

size_t				print_arg_uint(va_list *args, t_finfo *fmt)
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