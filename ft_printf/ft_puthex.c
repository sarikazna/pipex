/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srudman <srudman@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 20:57:41 by srudman           #+#    #+#             */
/*   Updated: 2023/07/07 14:58:04 by srudman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthex(unsigned int nbr, t_struct *count, char *base)
{
	if (nbr >= 16)
		ft_puthex(nbr / 16, count, base);
	ft_putchar(base[nbr % 16], count);
}

/*
#include <stdio.h>
int	main(void)
{
	t_struct count;
	
	count.len = 0;
	ft_puthex_low(4963345, &count);
	printf ("\n%d\n", count.len);
	return (0);
}
*/