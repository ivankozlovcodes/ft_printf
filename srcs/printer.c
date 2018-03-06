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

	f = fmt->format;
	if (f == 'd')
		ft_putnbr(*(int *)p);
	return (ft_nbrlen(p));
}

size_t	print_arg_int(va_list *args, t_finfo *fmt)
{
	long long int	n;

	n = (int)va_arg(*args, long long int);
	return (ft_putfmt((void *)&n, fmt));
}