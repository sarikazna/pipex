/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srudman <srudman@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 13:59:33 by srudman           #+#    #+#             */
/*   Updated: 2023/04/25 18:11:10 by srudman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= '0' && c <= '9') || (c > 64 && c < 91) || (c > 96 && c < 123))
		return (1);
	return (0);
}

/*
#include <stdio.h>
int	main(void)
{
	printf ("%d\n", ft_isalnum('s'));
    return (0);
}
*/
