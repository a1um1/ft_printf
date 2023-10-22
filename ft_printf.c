/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlakchai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 21:43:22 by tlakchai          #+#    #+#             */
/*   Updated: 2023/10/22 22:45:16 by tlakchai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	do_format(t_ptf_cfg *ptf_cfg)
{
	ptf_cfg->fmt++;
	if (*(ptf_cfg->fmt) == 's')
		format_string(ptf_cfg);
	else if (*ptf_cfg->fmt == 'c')
		ptf_cfg->size += write(1, &(char){va_arg(ptf_cfg->ap, int)}, 1);
	else if (*(ptf_cfg->fmt) == 'i' || *(ptf_cfg->fmt) == 'd')
		format_number(ptf_cfg, 10, 0);
	else if (*(ptf_cfg->fmt) == 'u')
		format_unumber(ptf_cfg, 10, 0);
	else if (*(ptf_cfg->fmt) == 'p')
		format_mem(ptf_cfg);
	else if (*(ptf_cfg->fmt) == 'x' || *(ptf_cfg->fmt) == 'X')
		format_unumber(ptf_cfg, 16, (*(ptf_cfg->fmt) == 'X'));
	else if (*(ptf_cfg->fmt) == '%')
		ptf_cfg->size += write(1, &(char){'%'}, 1);
	else if (*(ptf_cfg->fmt) == 0)
	{
		va_end(ptf_cfg->ap);
		ptf_cfg->size = -1;
	}
	else
		ptf_cfg->size += write(1, --(ptf_cfg->fmt), 1);
}

int	ft_printf(const char *fmt, ...)
{
	t_ptf_cfg	ptf_cfg;

	ptf_cfg.size = 0;
	ptf_cfg.fmt = (t_string) fmt;
	va_start(ptf_cfg.ap, fmt);
	while (*(ptf_cfg.fmt) && ptf_cfg.size >= 0)
	{
		if (*(ptf_cfg.fmt) == '%')
			do_format(&ptf_cfg);
		else
			ptf_cfg.size += write(1, ptf_cfg.fmt, 1);
		ptf_cfg.fmt++;
	}
	va_end(ptf_cfg.ap);
	return (ptf_cfg.size);
}