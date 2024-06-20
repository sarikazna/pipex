/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srudman <srudman@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 19:45:24 by srudman           #+#    #+#             */
/*   Updated: 2023/04/22 23:02:19 by srudman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*tmp;

	tmp = s;
	while (n--)
		*tmp++ = '\0';
}

/*
#include <stdio.h>
int main(void)
{
    char s[] = "Beethoven, 7th Symphony, 2nd Movement";
    size_t n = 5;
    ft_bzero(s + 14, n);
    printf ("%s\n", s);
    return (0);
}
*/