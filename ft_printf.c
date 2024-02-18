/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlakchai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 21:43:22 by tlakchai          #+#    #+#             */
/*   Updated: 2024/02/18 23:14:02 by tlakchai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	do_format(t_ptf_cfg *ptf_cfg, va_list arg)
{
	ptf_cfg->fmt++;
	if (*(ptf_cfg->fmt) == 's')
		format_string(ptf_cfg, arg);
	else if (*ptf_cfg->fmt == 'c')
		write_handler(ptf_cfg, &(char){va_arg(arg, int)}, 1);
	else if (*(ptf_cfg->fmt) == 'i' || *(ptf_cfg->fmt) == 'd')
		format_number(ptf_cfg, arg, "0123456789");
	else if (*(ptf_cfg->fmt) == 'u')
		format_unumber(ptf_cfg, arg, "0123456789");
	else if (*(ptf_cfg->fmt) == 'p')
		format_mem(ptf_cfg, arg);
	else if (*(ptf_cfg->fmt) == 'x')
		format_unumber(ptf_cfg, arg, "0123456789abcdef");
	else if (*(ptf_cfg->fmt) == 'X')
		format_unumber(ptf_cfg, arg, "0123456789ABCDEF");
	else if (*(ptf_cfg->fmt) == '%')
		write_handler(ptf_cfg, "%", 1);
	else if (*(ptf_cfg->fmt) == 0)
		ptf_cfg->size = -1;
	else
		write_handler(ptf_cfg, &(char){*(ptf_cfg->fmt)}, 1);
}

int	ft_vprintf(t_ptf_cfg ptf_cfg, va_list arg)
{
	while (*(ptf_cfg.fmt) != 0 && ptf_cfg.size >= 0)
	{
		if (*(ptf_cfg.fmt) == '%')
			do_format(&ptf_cfg, arg);
		else
			write_handler(&ptf_cfg, ptf_cfg.fmt, 1);
		ptf_cfg.fmt++;
	}
	va_end(arg);
	return (ptf_cfg.size);
}

int	ft_dprintf(const int fd, const char *fmt, ...)
{
	t_ptf_cfg	ptf_cfg;
	va_list		arg;

	ptf_cfg.size = 0;
	ptf_cfg.fd = fd;
	ptf_cfg.fmt = (char *) fmt;
	va_start(arg, fmt);
	return (ft_vprintf(ptf_cfg, arg));
}

int	ft_printf(const char *fmt, ...)
{
	t_ptf_cfg	ptf_cfg;
	va_list		arg;

	ptf_cfg.size = 0;
	ptf_cfg.fd = 1;
	ptf_cfg.fmt = (char *) fmt;
	va_start(arg, fmt);
	return (ft_vprintf(ptf_cfg, arg));
}
