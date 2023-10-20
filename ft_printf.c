/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 21:43:22 by tlakchai          #+#    #+#             */
/*   Updated: 2023/10/20 09:26:21 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *fmt, ...)
{
	t_ptf_cfg	ptf_base;

	ptf_base.size = 0;
	va_start(ptf_base.ap, fmt);
	while (*fmt)
	{
		if (*fmt == '%')
		{
			fmt++;
			if (*fmt == 's')
				format_string(&ptf_base);
			else if (*fmt == 'c')
				format_char(&ptf_base);
			else if (*fmt == 'i' || *fmt == 'd')
				format_number(&ptf_base, 10, 0);
			else if (*fmt == 'u')
				format_number(&ptf_base, 10, 0);
			else if (*fmt == 'p')
				format_mem(&ptf_base);
			else if (*fmt == 'x' || *fmt == 'X')
				format_number(&ptf_base, 16, (*fmt == 'X'));
			else if (*fmt == '%')
				format_percent(&ptf_base);
			else if (*fmt == 0)
			{
				va_end(ptf_base.ap);
				return (-1);
			}
			else
				ptf_base.size += write(1, --fmt, 1);
		}
		else
			ptf_base.size += write(1, fmt, 1);
		fmt++;
	}
	va_end(ptf_base.ap);
	return (ptf_base.size);
}

int	main(void)
{
	void	*x;

	x = malloc(20);
	if (!x)
		return (0);
	printf(" Our (%d Bytes)\n", ft_printf("%p",x));
	printf(" System (%d Bytes)\n", printf("%p", x));
	free(x);
	return (0);
}
