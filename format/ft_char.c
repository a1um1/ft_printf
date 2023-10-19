/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlakchai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 22:00:31 by tlakchai          #+#    #+#             */
/*   Updated: 2023/10/03 22:13:58 by tlakchai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int format_char(va_list ap)
{
    char    c;

    c = (char) va_arg(ap, int);
    write(1, &c, 1);
	return (1);
}