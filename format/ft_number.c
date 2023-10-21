/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_number.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlakchai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 22:24:52 by tlakchai          #+#    #+#             */
/*   Updated: 2023/10/21 15:23:58 by tlakchai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	write_num(int x)
{
	return (write(1, &x, 1));
}

int	ft_putnbr_base(size_t d, int size, unsigned long base, int uppercase)
{
	if (d >= base)
		size += ft_putnbr_base(d / base, 0, base, uppercase);
	if (d % base >= 10)
		size += write_num((d % base) + 87 - uppercase * 32);
	else
		size += write_num((d % base) + 48);
	return (size);
}

void	format_number(t_ptf_cfg *pf_cfg, int base, int uppercase)
{
	int	d;

	d = va_arg(pf_cfg->ap, int);
	if (d < 0)
	{
		d = -d;
		pf_cfg->size += write(1, "-", 1);
	}
	pf_cfg->size += ft_putnbr_base((unsigned long) d, 0, base, uppercase);
}

void	format_mem(t_ptf_cfg *pf_cfg)
{
	size_t	d;

	d = va_arg(pf_cfg->ap, unsigned long);
	pf_cfg->size += ft_putnbr_base(d, write(1, "0x", 2), 16, 0);
}
