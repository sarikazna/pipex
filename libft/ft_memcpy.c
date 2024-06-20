/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srudman <srudman@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 19:24:42 by srudman           #+#    #+#             */
/*   Updated: 2023/04/28 20:20:36 by srudman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*tmp_d;
	const char	*tmp_s;

	if (dest == NULL && src == NULL)
		return (NULL);
	tmp_d = dest;
	tmp_s = src;
	while (n--)
	{
		*tmp_d = *tmp_s;
		tmp_s++;
		tmp_d++;
	}
	return (dest);
}

/*
#include <stdio.h>
int  main(void)
{
    char src[] = "I like big butts and I cannot lie";
    char dest[] = "Baby Got Back";
    size_t n = 15;
    ft_memcpy(dest, src, n);
    printf("%s\n", dest);
}
*/