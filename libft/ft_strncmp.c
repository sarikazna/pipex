/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srudman <srudman@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 14:48:06 by srudman           #+#    #+#             */
/*   Updated: 2023/04/25 20:12:02 by srudman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*s01;
	unsigned char	*s02;

	s01 = (unsigned char *)s1;
	s02 = (unsigned char *)s2;
	while (*s01 && *s02 && n)
	{
		if (*s01 != *s02)
			return (*s01 - *s02);
		n--;
		s01++;
		s02++;
	}
	if (n == 0)
		return (0);
	return (*s01 - *s02);
}

/*
#include <stdio.h>
int	main(void)
{
	char	s1[] = "SSSara";
	char	s2[] = "SSTRudman";
	size_t	n = 3;
	printf("%d\n", ft_strncmp(s1, s2, n));
}
*/