/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlakchai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 22:00:31 by tlakchai          #+#    #+#             */
/*   Updated: 2023/10/22 22:45:52 by tlakchai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	format_string(t_ptf_cfg *pf_cfg)
{
	t_string	s;

	s = va_arg(pf_cfg->ap, char *);
	if (s == NULL)
	{
		pf_cfg->size += write(1, "(null)", ft_strlen("(null)"));
		return ;
	}
	pf_cfg->size += write(1, s, ft_strlen(s));
}
