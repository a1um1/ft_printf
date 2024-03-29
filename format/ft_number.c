/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_number.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlakchai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 22:24:52 by tlakchai          #+#    #+#             */
/*   Updated: 2024/01/01 04:25:12 by tlakchai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	format_unumber_base(t_ptf_cfg *ptf_cfg, size_t n, char *base)
{
	char	output[32];
	int		output_idx;
	int		base_len;

	base_len = ft_strlen(base);
	output_idx = 0;
	if (n == 0)
		output[output_idx++] = base[0];
	while (n > 0)
	{
		output[output_idx++] = base[n % base_len];
		n /= base_len;
	}
	while (output_idx > 0)
		write_handler(ptf_cfg, &(output[--output_idx]), 1);
}

void	format_number(t_ptf_cfg *pf_cfg, va_list arg, char *base)
{
	long	d;

	d = (long) va_arg(arg, int);
	if (d < 0)
	{
		d = -d;
		write_handler(pf_cfg, "-", 1);
	}
	format_unumber_base(pf_cfg, d, base);
}

void	format_unumber(t_ptf_cfg *pf_cfg, va_list arg, char *base)
{
	unsigned int	d;

	d = va_arg(arg, unsigned int);
	format_unumber_base(pf_cfg, d, base);
}

void	format_mem(t_ptf_cfg *pf_cfg, va_list arg)
{
	size_t	d;

	d = va_arg(arg, size_t);
	write_handler(pf_cfg, "0x", 2);
	format_unumber_base(pf_cfg, (size_t) d, "0123456789abcdef");
}
