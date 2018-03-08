/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 09:45:05 by ikozlov           #+#    #+#             */
/*   Updated: 2018/03/07 21:21:25 by ikozlov          ###   ########.fr       */
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

# define FLAGS "#0- +"

# define THREE_BYTES_MASK (0xE08080)
# define TWO_BYTES_MASK (0xC080)
# define FOUR_BYTES_MASK (0xF0808080)

typedef struct		s_finfo
{
	char			format;
	char			*p;
	char			*base;
	int				modifier;
	int				precision;
	int				width;
	int				padding;
	char			flags[6];
	char			padding_char;
}					t_finfo;

size_t					ft_printf(const char *fmt, ...);

size_t				process_arg(va_list *args, char **ptr);

size_t				print_arg_int(va_list *args, t_finfo *fmt);
size_t				print_arg_uint(va_list *args, t_finfo *fmt);
size_t				print_arg_char(va_list *args, t_finfo *fmt);
size_t				print_arg_ptr(va_list *args, t_finfo *fmt);
size_t				ft_putfmtc(char c, t_finfo *fmt);

int					skipstr(char **s1, char *s2);
int					skipchr(char **s, char c);
int					ft_prsnbr(char **s, int *dst);
char				*ft_toprecision(char *s, int n);
char				*ft_addchartostr(char *s, char c, int times, int dir);
void				ft_putnchar(char c, int n);
int					has_flag(t_finfo *f, char flag);

# define MAX(a, b) ((a) > (b) ? (a) : (b))

#endif