/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdecimal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srudman <srudman@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 20:57:41 by srudman           #+#    #+#             */
/*   Updated: 2023/07/07 14:57:10 by srudman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putdecimal(unsigned int nbr, t_struct *count)
{
	char	*base;

	base = "0123456789";
	if (nbr >= 10)
		ft_putdecimal(nbr / 10, count);
	ft_putchar(base[nbr % 10], count);
}

/*
#include <stdio.h>
int	main(void)
{
	t_struct count;
	
	count.len = 0;
	ft_putdecimal(496, &count);
	printf ("\n%d\n", count.len);
	return (0);
}
*/
