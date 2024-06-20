/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srudman <srudman@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 17:29:32 by srudman           #+#    #+#             */
/*   Updated: 2023/07/07 18:25:55 by srudman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *s, t_struct *count)
{
	int	i;

	if (s == NULL)
		s = "(null)";
	i = 0;
	while (s[i])
	{
		ft_putchar(s[i], count);
		i++;
	}
}
