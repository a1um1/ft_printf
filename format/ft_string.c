/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlakchai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 22:00:31 by tlakchai          #+#    #+#             */
/*   Updated: 2023/10/23 01:59:04 by tlakchai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	format_string(t_ptf_cfg *pf_cfg)
{
	t_string	s;

	s = va_arg(pf_cfg->ap, char *);
	if (s == NULL)
		return (write_handler(pf_cfg, "(null)", ft_strlen("(null)")));
	write_handler(pf_cfg, s, ft_strlen(s));
}
