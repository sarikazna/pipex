/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srudman <srudman@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 20:07:04 by srudman           #+#    #+#             */
/*   Updated: 2023/04/25 18:32:48 by srudman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*tmp_d;
	const char	*tmp_s;

	tmp_d = dest;
	tmp_s = src;
	if (dest == src)
		return (dest);
	else if (tmp_s < tmp_d)
	{
		tmp_s = tmp_s + n;
		tmp_d = tmp_d + n;
		while (n--)
			*--tmp_d = *--tmp_s;
	}
	else
	{
		while (n--)
			*tmp_d++ = *tmp_s++;
	}
	return (dest);
}

/*
#include <stdio.h>
int  main(void)
{
    char src[] = "lorem ipsum dolor sit amet, consectetur";
    char dest[] = "lorem ipsum dolor sit amet";
    size_t n = 8;
    ft_memmove(dest, src, n);
    printf("%s\n", dest);
}
*/
