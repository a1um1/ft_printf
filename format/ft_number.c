/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_number.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlakchai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 22:24:52 by tlakchai          #+#    #+#             */
/*   Updated: 2023/10/03 22:37:37 by tlakchai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void write_num(int x)
{
	write(1, &x, 1);
}

int write_numb(long d, int size)
{
	if (d < 0)
	{
		d = -d;
		size++;
		write(1, "-", 1);
	}
	if (d >= 10)
		size += write_numb(d / 10, 0);
	write_num((d % 10) + 48);
	size++;
	return (size);
}

int format_number(va_list ap)
{
	int	d;

	d = va_arg(ap, int);
	return (write_numb(d, 0));	
}