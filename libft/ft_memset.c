/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srudman <srudman@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 19:42:50 by srudman           #+#    #+#             */
/*   Updated: 2023/04/22 23:23:49 by srudman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*tmp;
	unsigned char	converted_c;

	tmp = s;
	converted_c = (unsigned char)c;
	while (n)
	{
		*tmp = converted_c;
		tmp++;
		n--;
	}
	return (s);
}

/*
#include <stdio.h>
int main(void)
{
    char s[] = "V dolini tihi je vasica mala, 
		v vecernem mraku vse ze mirno spava. 
		Le eno okon se odprto je, na njem slonelo zalostno dekle.";
    int c = '.';
    size_t n = 10;
    ft_memset(s + 50, c, n);
    printf ("Own function: %s\n", s);
    return (0);
}
*/