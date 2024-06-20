/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srudman <srudman@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 18:27:11 by srudman           #+#    #+#             */
/*   Updated: 2023/07/15 18:50:32 by srudman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int n, t_struct *count)
{
	char	c;

	if (n == -2147483648)
		ft_putstr("-2147483648", count);
	else if (n < 0)
	{
		ft_putchar('-', count);
		n = -n;
		ft_putnbr(n, count);
	}
	else if (n > 9)
	{
		ft_putnbr(n / 10, count);
		ft_putnbr(n % 10, count);
	}
	else
	{
		c = n + '0';
		ft_putchar(c, count);
	}
}

/*
#include <stdio.h>
int	main(void)
{
	t_struct count;
	
	count.len = 0;
	ft_putnbr(-1, &count);
	printf ("\n%d\n", count.len);
	return (0);
}
*/
