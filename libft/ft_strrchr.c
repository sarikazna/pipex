/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srudman <srudman@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 14:33:56 by srudman           #+#    #+#             */
/*   Updated: 2023/04/25 19:47:12 by srudman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t			len;
	unsigned char	d;

	d = c;
	len = ft_strlen(s);
	if (d == '\0')
		return ((char *)(s + len));
	while (len)
	{
		len--;
		if ((unsigned char)s[len] == d)
			return ((char *)(s + len));
	}
	return (NULL);
}

/*
#include <stdio.h>
int main(void)
{
    printf("%p\n", ft_strrchr("teste", ""));
    return (0);
}
*/