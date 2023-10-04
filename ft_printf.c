/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlakchai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 21:43:22 by tlakchai          #+#    #+#             */
/*   Updated: 2023/10/04 07:02:38 by tlakchai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf(const char *fmt, ...)
{
	int		size;
	va_list ap;

    size = 0;
	va_start(ap, fmt);
	while (*fmt)
	{
		if (*fmt == '%')
		{
			fmt++;
			if (*fmt == 'c')
				size += format_char(ap);
			else if (*fmt == 's')
				size += format_string(ap);
			else if (*fmt == 'i' || *fmt == 'd')
				size += format_number(ap);
			else if (*fmt == 'u')
				size += format_number_unsinged(ap);
			else if (*fmt == '%')
				size += format_percent(ap);
			else if (*fmt == 0)
			{
				va_end(ap);
				return (-1);
			}
			else
			{
				write(1, --fmt, 1);
				size++;
			}
		}
		else
		{
			write(1, fmt, 1);
			size++;
		}
		fmt++;
	}
	va_end(ap);
	return (size);
}

int main(void)
{
    printf("%d\n", ft_printf("%%%%%"));
	printf("%d\n", printf("%%%%%"));
    return (0);
}