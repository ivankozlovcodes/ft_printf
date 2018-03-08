/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 15:55:20 by ikozlov           #+#    #+#             */
/*   Updated: 2018/03/07 22:19:43 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		parse_wildchar(int *dst, char **ptr)
{
	// todo: handle *
	if (!ft_prsnbr(ptr, dst))
		return (0);
	return (1);
}

void	parse_flags(char **ptr, t_finfo *fmt)
{
	int		i;

	i = 0;
	while (ft_strchr(FLAGS, **ptr))
	{
		if (!ft_strchr(fmt->flags, **ptr))
			fmt->flags[i++] = **ptr;
		(*ptr)++;
	}
	fmt->flags[i] = '\0';
}

char	*parse_arg(t_finfo *fmt, char **ptr)
{
	char	*tmp;

	parse_flags(ptr, fmt);
	parse_wildchar(&(fmt->width), ptr);
	if (fmt->width < 0)
	{
		fmt->width = -fmt->width;
		fmt->padding = -1;
	}
	if (skipchr(ptr, '.'))
		parse_wildchar(&(fmt->precision), ptr);
	tmp = *ptr;
	if ((tmp = ft_strstredl(*ptr, "ll")))
		fmt->modifier = MDF_LL;
	else if ((fmt->modifier = ft_strchri(FORMATS, **ptr)) != -1)
		(*ptr)++;
	else if ((tmp = ft_strstredl(*ptr, "hh")))
		fmt->modifier = MDF_HH;
	*ptr = tmp ? tmp : *ptr;
	fmt->format = **ptr;
	if (*ptr != '\0')
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
	else
		return (ft_putfmtc(f, fmt));
	return (0);
}

size_t	process_arg(va_list *args, char **ptr)
{
	t_finfo	fmt;

	fmt.modifier = -1;
	fmt.width = 0;
	fmt.padding = 1;
	fmt.precision = -1;
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
