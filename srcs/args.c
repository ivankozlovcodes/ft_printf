/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 15:55:20 by ikozlov           #+#    #+#             */
/*   Updated: 2018/03/07 12:15:54 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*parse_arg(va_list *args, t_finfo *fmt, char **ptr)
{
	char	*tmp;

	fmt->modifier = -1;
	tmp = *ptr;
	if ((tmp = ft_strstredl(*ptr, "ll")))
		fmt->modifier = MDF_LL;
	else if ((tmp = ft_strstredl(*ptr, "l")))
		fmt->modifier = MDF_L;
	fmt->format = **ptr;
	args++; //for compiling
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
			*ptr = parse_arg(args, &fmt, ptr);
			return (print_arg(args, &fmt));
		}
	}
	return (0);
}
