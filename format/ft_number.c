/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_number.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 22:24:52 by tlakchai          #+#    #+#             */
/*   Updated: 2023/10/20 09:20:50 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	write_num(int x)
{
	write(1, &x, 1);
	return (1);
}

int	write_numb(long d, int size, int base, int uppercase)
{
	if (d < 0)
	{
		d = -d;
		size++;
		write(1, "-", 1);
	}
	if (d >= base)
		size += write_numb(d / base, 0, base, uppercase);
	if (d % base >= 10)
		size += write_num((d % base) + 87 - uppercase * 32);
	else
		size += write_num((d % base) + 48);
	return (size);
}

int	format_number(va_list ap, int base, int uppercase)
{
	int	d;

	d = va_arg(ap, int);
	return (write_numb((long) d, 0, base, uppercase));
}

int	format_mem(va_list ap)
{
	void	*d;

	d = va_arg(ap, void *);
	write(1, "0x", 2);
	return (write_numb((long) d, 2, 16, 0));
}