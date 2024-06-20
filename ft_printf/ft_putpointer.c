/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srudman <srudman@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 20:57:41 by srudman           #+#    #+#             */
/*   Updated: 2023/08/06 14:22:40 by srudman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_pointer_hex(unsigned long long n, t_struct *count, char *base)
{
	if (n >= 16)
		ft_pointer_hex(n / 16, count, base);
	ft_putchar(base[n % 16], count);
}

void	ft_putpointer(void *ptr, t_struct *count)
{
	unsigned long long		n;

	if (ptr == 0)
	{
		ft_putstr("(nil)", count);
		return ;
	}
	n = (unsigned long long)ptr;
	ft_putstr("0x", count);
	ft_pointer_hex(n, count, "0123456789abcdef");
}
