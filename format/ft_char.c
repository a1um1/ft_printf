/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 22:00:31 by tlakchai          #+#    #+#             */
/*   Updated: 2023/10/20 05:11:03 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	format_char(t_ptf_cfg *pf_cfg)
{
	char	c;

	c = va_arg(pf_cfg->ap, int);
	pf_cfg->size += write(1, &c, 1);
}
