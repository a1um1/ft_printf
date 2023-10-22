/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_number.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlakchai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 22:24:52 by tlakchai          #+#    #+#             */
/*   Updated: 2023/10/22 17:03:28 by tlakchai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	write_num(int x)
{
	return (write(1, &x, 1));
}

int	ft_putnbr_base(size_t d, int size, size_t base, int uppercase)
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
	long	d;

	d = (long) va_arg(pf_cfg->ap, int);
	if (d < 0)
	{
		d = -d;
		if (base != 16)
			pf_cfg->size += write(1, "-", 1);
	}
	pf_cfg->size += ft_putnbr_base(d, 0, base, uppercase);
}

void	format_unumber(t_ptf_cfg *pf_cfg, int base, int uppercase)
{
	unsigned int	d;

	d = va_arg(pf_cfg->ap, unsigned int);
	pf_cfg->size += ft_putnbr_base(d, 0, base, uppercase);
}

void	format_mem(t_ptf_cfg *pf_cfg)
{
	size_t	d;

	d = va_arg(pf_cfg->ap, size_t);
	pf_cfg->size += ft_putnbr_base((size_t) d, write(1, "0x", 2), 16, 0);
}
