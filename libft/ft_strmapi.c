/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srudman <srudman@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 12:00:40 by srudman           #+#    #+#             */
/*   Updated: 2023/04/28 15:23:50 by srudman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
char	ft_test(unsigned int i, char c)
{
	return (c + i);
}
*/

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*s_tmp;
	unsigned int	i;

	s_tmp = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (s_tmp == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		s_tmp[i] = f(i, s[i]);
		i++;
	}
	s_tmp[i] = '\0';
	return (s_tmp);
}

/*
#include <stdio.h>
int	main(void)
{
	char const	*str = " I want ice cream!";
	char		*new_str;

	new_str = ft_strmapi(str, &ft_test);
	printf("Input string: %s\n", str);
	printf("Output string: %s\n", new_str);
	free(new_str);
	return (0);
}
*/