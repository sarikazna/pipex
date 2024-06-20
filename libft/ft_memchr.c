/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srudman <srudman@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 15:53:00 by srudman           #+#    #+#             */
/*   Updated: 2023/04/28 20:16:52 by srudman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char		converted_c;
	const unsigned char	*tmp_s;

	converted_c = (unsigned char)c;
	tmp_s = s;
	while (n)
	{
		if (*tmp_s == converted_c)
			return ((void *)tmp_s);
		tmp_s++;
		n--;
	}
	return (NULL);
}

/*
#include <stdio.h>
int main(void)
{
    char s[] = {0, 1, 2 ,3 ,4 ,5};
	char *ptr = ft_memchr(s, 0, 1);
    printf ("Own function: %p\n", ptr);
    return (0);
}
*/
