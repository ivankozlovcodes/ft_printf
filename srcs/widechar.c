/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   widechar.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 21:07:29 by ikozlov           #+#    #+#             */
/*   Updated: 2018/03/09 21:07:45 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_print_wchar(wint_t c)
{
	int		output;
	size_t	len;

	output = FOUR_BYTES_MASK;
	if (c <= 0x7F)
	{
		output = c & 127;
		len = 1;
	}
	else
	{
		output = get_mask(c, &len);
		output |= (((c >> 6) & 0x3F) << 8) | (c & 0x3F);
		if (c > 0x7FF)
			output |= (((c >> 12) & 0xF) << 16);
		if (c > 0xFFFF)
			output |= (((c >> 18) & 0x7) << 24);
	}
	output = to_little_endian(output);
	write(1, &output, 4);
	return (len);
}
