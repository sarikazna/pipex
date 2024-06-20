/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srudman <srudman@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 21:32:13 by srudman           #+#    #+#             */
/*   Updated: 2023/04/25 18:43:22 by srudman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;

	src_len = ft_strlen(src);
	i = 0;
	if (size > 0)
	{
		while (src[i] && size - 1 > i)
		{
			*dst = src[i];
			dst++;
			i++;
		}
		*dst = '\0';
	}
	return (src_len);
}

// The value returned is always the size of string src 
// regardless of how many characters are copied.
/*
#include <stdio.h>
int main(void)
{
    char dst[] = "V dolini tihi je vasica mala.";
    char src[] = "Ansabel Avesniki.";
    size_t size = 10;
    printf ("Size of src essentially: %zu\n", ft_strlcpy(dst, src, size));
    return (0);
}
*/