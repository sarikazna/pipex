/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srudman <srudman@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 21:07:29 by srudman           #+#    #+#             */
/*   Updated: 2024/03/13 19:20:06 by srudman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_countwords(char const *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	if (s[i] != c)
		count++;
	i++;
	while (s[i])
	{
		if (s[i] != c && s[i - 1] == c)
			count++;
		i++;
	}
	return (count);
}

char	**ft_empty_result(void)
{
	char	**result;

	result = malloc(sizeof(char *));
	if (!result)
		return (NULL);
	result[0] = NULL;
	return (result);
}

char	*ft_fill_word(char *s, char c)
{
	char	*tmp;
	int		i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	tmp = malloc(sizeof(char) * (i + 1));
	if (tmp == NULL)
		return (NULL);
	i = -1;
	while (s[++i] && s[i] != c)
		tmp[i] = s[i];
	tmp[i] = '\0';
	return (tmp);
}

void	ft_fill_result(const char *s, char c, char **result)
{
	int		j;
	int		i;

	j = 0;
	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			result[j++] = ft_fill_word(&((char *)s)[i], c);
			while (*s && *s != c)
				s++;
		}
	}
	result[j] = NULL;
}

char	**ft_split(const char *s, char c)
{
	char	**result;

	if (!s || !*s)
		return (ft_empty_result());
	result = malloc(sizeof(char *) * (ft_countwords(s, c) + 1));
	if (result == NULL)
		return (NULL);
	ft_fill_result(s, c, result);
	return (result);
}

/*
#include <stdio.h>
int main(void)
{
    char *s = "hello itsme ddd";
    char c = ' ';
    int i = 0;
	char	**result = (ft_split(s, c));
	while (result[i] != NULL)
	{
		printf("%s\n", result[i]);
		i++;
	}
}
*/