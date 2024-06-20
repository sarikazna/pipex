/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srudman <srudman@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 15:18:15 by srudman           #+#    #+#             */
/*   Updated: 2023/04/25 20:38:26 by srudman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	if (!(*little))
		return ((char *)big);
	while (big[i] && i < len)
	{
		j = 0;
		k = i;
		while (big[k] == little[j] && k < len && little[j])
		{
			k++;
			j++;
		}
		if (little[j] == '\0')
			return ((char *)(big + i));
		i++;
	}
	return (NULL);
}

/*
#include <stdio.h>
int main(void)
{
    const char *big = "lorem ipsum dolor sit amet";
    const char *little = "lorem";
    size_t len = 15;
    printf("%s\n", ft_strnstr(big, little, len));
    return (0);
}
*/