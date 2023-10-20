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
	int		size;
	va_list	ap;

	size = 0;
	va_start(ap, fmt);
	while (*fmt)
	{
		if (*fmt == '%')
		{
			fmt++;
			if (*fmt == 's')
				size += format_string(ap);
			else if (*fmt == 'c')
				size += format_char(ap);
			else if (*fmt == 'i' || *fmt == 'd')
				size += format_number(ap, 10, 0);
			else if (*fmt == 'u')
				size += format_number(ap, 10, 0);
			else if (*fmt == 'p')
				size += format_mem(ap);
			else if (*fmt == 'x' || *fmt == 'X')
				size += format_number(ap, 16, (*fmt == 'X'));
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

int	main(void)
{
	void	*x;

	x = malloc(20);
	if (!x)
		return (0);
	printf("%d\n", ft_printf("%",x));
	printf("%d\n", printf("%", x));
	free(x);
	return (0);
}
