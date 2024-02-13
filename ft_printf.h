/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml <ml@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 21:42:34 by tlakchai          #+#    #+#             */
/*   Updated: 2024/02/12 02:18:09 by ml               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft/libft.h"

typedef struct s_ptf_cfg
{
	int			size;
	char		*fmt;
	int			fd;
}	t_ptf_cfg;

int		ft_printf(const char *fmt, ...);
int		ft_dprintf(int fd, const char *fmt, ...);

void	format_string(t_ptf_cfg *pf_cfg, va_list arg);
void	format_mem(t_ptf_cfg *pf_cfg, va_list arg);
void	format_number(t_ptf_cfg *pf_cfg, va_list arg, char *base);
void	format_unumber(t_ptf_cfg *pf_cfg, va_list arg, char *base);
void	write_handler(t_ptf_cfg *ptf_cfg, const char *c, size_t len);

#endif