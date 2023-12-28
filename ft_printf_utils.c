/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlakchai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 01:45:08 by tlakchai          #+#    #+#             */
/*   Updated: 2023/12/29 04:35:40 by tlakchai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	write_handler(t_ptf_cfg *ptf_cfg, char *c, size_t len)
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
