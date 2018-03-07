/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 17:01:28 by ikozlov           #+#    #+#             */
/*   Updated: 2018/03/05 17:53:09 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		main(void)
{
	int	n;
	long long	lln;

	n = 3;
	lln = 9223372036854775807;
	ft_printf("Hello world!\n");
	ft_printf("Number: %d\n", n);
	ft_printf("ll number: %lld\n", lln);
	return (0);
}