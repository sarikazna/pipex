/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srudman <srudman@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 14:02:24 by srudman           #+#    #+#             */
/*   Updated: 2023/04/28 19:53:02 by srudman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if ((unsigned int) c <= 127)
		return (1);
	return (0);
}

/*
#include <stdio.h>
int	main(void)
{
	printf ("%d\n", ft_isascii('s'));
    return (0);
}
*/