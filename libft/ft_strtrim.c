/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srudman <srudman@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 18:06:53 by srudman           #+#    #+#             */
/*   Updated: 2023/04/26 17:40:35 by srudman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	in_charset(char const s, char const *set)
{
	while (*set)
	{
		if (*set == s)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_cpy(char const *s1, size_t start, size_t end)
{
	int		j;
	char	*ptr;

	if (start == ft_strlen(s1))
	{
		ptr = malloc(1);
		if (ptr == NULL)
			return (NULL);
		ptr[0] = '\0';
		return (ptr);
	}
	ptr = (char *)malloc(sizeof(char) * (end - start + 1));
	if (ptr == NULL)
		return (NULL);
	j = 0;
	while (end > start)
		ptr[j++] = s1[start++];
	ptr[j] = '\0';
	return (ptr);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ptr;
	size_t	start;
	size_t	end;

	start = 0;
	while (s1[start] && in_charset(s1[start], set))
		start++;
	end = ft_strlen(s1);
	while (s1[end - 1] && in_charset(s1[end - 1], set))
		end--;
	ptr = ft_cpy(s1, start, end);
	return (ptr);
}

// #include <stdio.h>
// int main(void)
// {
//     char const *s = "<>.,abcd,,>";
//     char const *set = ".,<>";
//     printf("%s\n",ft_strtrim(s, set));
//     return (0);
// }
