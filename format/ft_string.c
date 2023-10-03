/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlakchai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 22:00:31 by tlakchai          #+#    #+#             */
/*   Updated: 2023/10/03 22:16:01 by tlakchai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

size_t ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return i;
}


int format_string(va_list ap)
{
    char	*s;
	int		str_size;
	
    s = va_arg(ap, char *);
	if (s == NULL)
	{
		str_size = ft_strlen("(null)");
    	write(1, "(null)", str_size);
		return (str_size);
	}
	str_size = ft_strlen(s);
    write(1, s, str_size);
	return (str_size);
}