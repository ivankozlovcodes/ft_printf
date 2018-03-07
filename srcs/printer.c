/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 16:21:54 by ikozlov           #+#    #+#             */
/*   Updated: 2018/03/05 17:52:24 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_putfmt(void *p, t_finfo *fmt)
{
	char			f;
	char			*s;

	f = fmt->format;
	s = ft_itoa(*(int *)p);
	if (f == 'd' || f == 'i')
		ft_putstr(s);
	return (ft_strlen(s));
}

size_t	print_arg_int(va_list *args, t_finfo *fmt)
{
	char			f;
	int				m;
	long long int	n;

	if (m == MDF_LL)
		n = (long)va_arg(*args, long long int);
	else
		n = (int)va_arg(*args, int);
	return (ft_putfmt((void *)&n, fmt));
}