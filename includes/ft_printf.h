/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 09:45:05 by ikozlov           #+#    #+#             */
/*   Updated: 2018/03/07 12:38:46 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <unistd.h>
# include <stdarg.h>
#include <wchar.h>

# define MDF_LL (0)
# define MDF_L (1)
# define MDF_H (2)
# define MDF_HH (3)
# define MDF_J (4)
# define MDF_Z (5)

# define OCTAL "01234567"
# define DECIMAL "0123456789"
# define HEX "0123456789abcdef"
# define HEX_UPPER "0123456789ABCDEF"

typedef struct		s_finfo
{
	char			format;
	char			*p;
	char			*base;
	int				modifier;
}					t_finfo;

size_t					ft_printf(const char *fmt, ...);

size_t				process_arg(va_list *args, char **ptr);

size_t				print_arg_int(va_list *args, t_finfo *fmt);
size_t				print_arg_uint(va_list *args, t_finfo *fmt);
size_t				print_arg_char(va_list *args, t_finfo *fmt);
size_t				print_arg_ptr(va_list *args, t_finfo *fmt);

#endif