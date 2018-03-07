/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 09:45:05 by ikozlov           #+#    #+#             */
/*   Updated: 2018/03/05 17:01:03 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <unistd.h>
# include <stdarg.h>

# define MDF_LL (0)

typedef struct		s_finfo
{
	char			format;
	char			*p;
	int				modifier;
}					t_finfo;

size_t					ft_printf(const char *fmt, ...);

size_t				process_arg(va_list *args, char **ptr);

size_t				print_arg_int(va_list *args, t_finfo *fmt);
size_t				print_arg_uint(va_list *args, t_finfo *fmt);

#endif