/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_number.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 22:24:52 by tlakchai          #+#    #+#             */
/*   Updated: 2023/10/22 17:06:09 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	format_unumber_base(t_ptf_cfg *ptf_cfg, size_t n, t_string base)
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
		ptf_cfg->size += write(1, &(output[--output_idx]), 1);
}

void	format_number(t_ptf_cfg *pf_cfg, t_string base)
{
	long	d;

	d = (long) va_arg(pf_cfg->ap, int);
	if (d < 0)
	{
		d = -d;
		pf_cfg->size += write(1, "-", 1);
	}
	format_unumber_base(pf_cfg, d, base);
}

void	format_unumber(t_ptf_cfg *pf_cfg, t_string base)
{
	unsigned int	d;

	d = va_arg(pf_cfg->ap, unsigned int);
	format_unumber_base(pf_cfg, d, base);
}

void	format_mem(t_ptf_cfg *pf_cfg)
{
	size_t	d;

	d = va_arg(pf_cfg->ap, size_t);
	pf_cfg->size += write(1, "0x", 2);
	format_unumber_base(pf_cfg, (size_t) d, "0123456789abcdef");
}
