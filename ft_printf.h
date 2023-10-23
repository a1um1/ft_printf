/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlakchai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 21:42:34 by tlakchai          #+#    #+#             */
/*   Updated: 2023/10/23 01:51:44 by tlakchai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft/libft.h"

typedef char	*t_string;

typedef struct s_ptf_cfg
{
	int			size;
	va_list		ap;
	t_string	fmt;
}	t_ptf_cfg;

int		ft_printf(const char *fmt, ...);

void	format_string(t_ptf_cfg *pf_cfg);
void	format_mem(t_ptf_cfg *pf_cfg);
void	format_number(t_ptf_cfg *pf_cfg, t_string base);
void	format_unumber(t_ptf_cfg *pf_cfg, t_string base);
void	write_handler(t_ptf_cfg *ptf_cfg, char *c, size_t len);

#endif