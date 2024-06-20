/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srudman <srudman@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 17:48:39 by srudman           #+#    #+#             */
/*   Updated: 2023/04/25 21:16:01 by srudman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	s_len;

	if (s == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
	{
		result = malloc(1);
		result[0] = 0;
		return (result);
	}
	if (start + len > s_len)
		len = s_len - start;
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (result == NULL)
		return (NULL);
	ft_memcpy(result, s + start, len);
	result[len] = '\0';
	return (result);
}

/* 
#include <stdio.h>
int main(void)
{
    char const *s = "Never know how much I love you, never know muc";
    unsigned int start = 10;
    size_t len = 0;
    printf("%s\n",ft_substr(s, start, len));
    return (0);
}
 */