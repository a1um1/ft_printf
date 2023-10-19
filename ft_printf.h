/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlakchai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 21:42:34 by tlakchai          #+#    #+#             */
/*   Updated: 2023/10/04 06:56:09 by tlakchai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF
# define FT_PRINTF

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft/libft.h"

int ft_printf(const char *fmt, ...);

int format_string(va_list ap);
int format_percent(va_list ap);
int format_char(va_list ap);
int format_number(va_list ap);
int format_number_unsinged(va_list ap);
    
#endif