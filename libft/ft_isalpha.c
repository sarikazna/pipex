/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srudman <srudman@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 14:58:02 by srudman           #+#    #+#             */
/*   Updated: 2023/04/22 23:06:52 by srudman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if (!((c > 64 && c < 91) || (c > 96 && c < 123)))
		return (0);
	return (1);
}

/*
#include <stdio.h>
int	main(void)
{
	printf ("%d\n", ft_isalpha('S'));
    return (0);
}
*/