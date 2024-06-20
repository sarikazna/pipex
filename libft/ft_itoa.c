/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srudman <srudman@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 19:31:59 by srudman           #+#    #+#             */
/*   Updated: 2023/04/26 17:33:04 by srudman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_divider(int digits)
{
	int	div;

	div = 1;
	while (digits)
	{
		div = div * 10;
		digits--;
	}
	return (div);
}

int	ft_digitcount(int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char	*ft_copy(char *ptr, int n, int digits)
{
	int	j;

	j = 0;
	if (n < 0)
	{
		ptr[j++] = '-';
		n = -n;
	}
	if (n == -2147483648)
	{
		ptr[j++] = '2';
		n = 147483648;
		digits--;
	}
	while (digits)
	{
		ptr[j] = ((n / (ft_divider(digits - 1))) + '0');
		n = n % ft_divider(digits - 1);
		j++;
		digits--;
	}
	ptr[j] = '\0';
	return (ptr);
}

char	*ft_itoa(int n)
{
	char	*ptr;
	int		digits;
	int		minus;

	minus = 0;
	if (n < 0)
		minus = 1;
	if (n == -2147483648)
		digits = 10;
	digits = ft_digitcount(n);
	ptr = (char *)malloc(sizeof(char) * (digits + minus + 1));
	if (ptr == NULL)
		return (NULL);
	ptr = ft_copy(ptr, n, digits);
	return (ptr);
}

/*
#include <stdio.h>
int main(void)
{
    printf("%s\n", ft_itoa(-2147483648));
    return (0);
}
*/