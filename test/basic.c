/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 17:15:39 by tlakchai          #+#    #+#             */
/*   Updated: 2023/10/22 17:09:57 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"


int	main(void)
{
	ft_printf(" Our %d written\n", ft_printf("Hello World %"));
	ft_printf(" Our %d written\n", printf("Hello World %"));
	// printf("Hello world %");
	return (0);
}