/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlakchai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 01:45:08 by tlakchai          #+#    #+#             */
/*   Updated: 2024/01/01 04:30:39 by tlakchai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	write_handler(t_ptf_cfg *ptf_cfg, const char *c, size_t len)
{
	int	code;

	if (ptf_cfg->size < 0)
		return ;
	code = write(ptf_cfg->fd, c, len);
	if (code < 0)
		ptf_cfg->size = -1;
	else
		ptf_cfg->size += code;
}
