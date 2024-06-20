/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srudman <srudman@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 19:54:44 by srudman           #+#    #+#             */
/*   Updated: 2023/04/28 20:37:52 by srudman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*ptr;
	int		i;

	ptr = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		*ptr = s[i++];
		ptr++;
	}
	*ptr = '\0';
	return (ptr - i);
}

/*
#include <stdio.h>
int main(void)
{
    printf("%s\n", ft_strdup("Frere Jacques"));
    return (0);
}
*/