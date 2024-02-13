/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlakchai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 22:00:31 by tlakchai          #+#    #+#             */
/*   Updated: 2024/01/01 04:39:45 by tlakchai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	format_string(t_ptf_cfg *pf_cfg, va_list arg)
{
	char	*str;


	str = va_arg(arg, char *);
	if (str == NULL)
		return (write_handler(pf_cfg, "(null)", 6));
	write_handler(pf_cfg, str, ft_strlen(str));
}
