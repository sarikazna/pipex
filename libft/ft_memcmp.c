/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srudman <srudman@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 16:40:52 by srudman           #+#    #+#             */
/*   Updated: 2023/04/25 20:26:55 by srudman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*tmp_s1;
	const unsigned char	*tmp_s2;

	tmp_s1 = s1;
	tmp_s2 = s2;
	while (n--)
	{
		if (*tmp_s1 != *tmp_s2)
			return (*tmp_s1 - *tmp_s2);
		if (n == 0)
			break ;
		tmp_s1++;
		tmp_s2++;
	}
	return (0);
}

/*
#include <stdio.h>
int	main(void)
{
	char	s1[] = "abcdefghij";
	char	s2[] = "abcdefgxyz";
	size_t	n = 7;
	printf("%d\n", ft_memcmp(s1, s2, n));
}
*/