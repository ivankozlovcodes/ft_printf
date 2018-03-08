/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 15:55:20 by ikozlov           #+#    #+#             */
/*   Updated: 2018/03/07 18:04:38 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		set_precision(int *dst, char **ptr)
{
	// todo: handle *
	if (!ft_prsnbr(ptr, dst))
		return (0);
	return (1);
}

char	*parse_arg(t_finfo *fmt, char **ptr)
{
	char	*tmp;

	if (skipchr(ptr, '.'))
		set_precision(&(fmt->precision), ptr);
	else
		fmt->precision = -1;
	fmt->modifier = -1;
	tmp = *ptr;
	if ((tmp = ft_strstredl(*ptr, "ll")))
		fmt->modifier = MDF_LL;
	else if ((tmp = ft_strstredl(*ptr, "l")))
		fmt->modifier = MDF_L;
	else if ((tmp = ft_strstredl(*ptr, "hh")))
		fmt->modifier = MDF_HH;
	else if ((tmp = ft_strstredl(*ptr, "h")))
		fmt->modifier = MDF_H;
	else if ((tmp = ft_strstredl(*ptr, "j")))
		fmt->modifier = MDF_J;
	else if ((tmp = ft_strstredl(*ptr, "z")))
		fmt->modifier = MDF_Z;
	*ptr = tmp ? tmp : *ptr;
	fmt->format = **ptr;
	// if (*ptr != '\0')
	(*ptr)++;
	return (*ptr);
}

size_t	print_arg(va_list *args, t_finfo *fmt)
{
	char	f;

	f = fmt->format;
	if (f == 'd' || f == 'i')
		return (print_arg_int(args, fmt));
	else if (ft_strchr("ouxX", f) != NULL)
		return (print_arg_uint(args, fmt));
	else if (f == 'c' || f == 'C')
		return (print_arg_char(args, fmt));
	else if (f == 's' || f == 'S')
		return (print_arg_ptr(args, fmt));
	return (0);
}

/*
** Prints an argument according to format specified
*/
size_t	process_arg(va_list *args, char **ptr)
{
	t_finfo	fmt;

	if (**ptr == '%')
	{
		(*ptr)++;
		if (*ptr != '\0')
		{
			*ptr = parse_arg(&fmt, ptr);
			return (print_arg(args, &fmt));
		}
	}
	return (0);
}
