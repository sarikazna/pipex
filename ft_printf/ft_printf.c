/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srudman <srudman@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 14:35:34 by srudman           #+#    #+#             */
/*   Updated: 2023/07/15 18:47:43 by srudman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_format(char c, va_list args, t_struct *count)
{
	if (c == 'i' || c == 'd')
		ft_putnbr(va_arg(args, int), count);
	else if (c == 'c')
		ft_putchar(va_arg(args, int), count);
	else if (c == '%')
		ft_putchar('%', count);
	else if (c == 's')
		ft_putstr(va_arg(args, char *), count);
	else if (c == 'p')
		ft_putpointer(va_arg(args, void *), count);
	else if (c == 'u')
		ft_putdecimal(va_arg(args, unsigned int), count);
	else if (c == 'x')
		ft_puthex(va_arg(args, unsigned int), count, "0123456789abcdef");
	else if (c == 'X')
		ft_puthex(va_arg(args, unsigned int), count, "0123456789ABCDEF");
}

int	ft_printf(const char *str, ...)
{
	int			i;
	t_struct	count;
	va_list		args;

	va_start(args, str);
	i = 0;
	count.len = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			ft_format(str[i], args, &count);
		}
		else
		{
			ft_putchar(str[i], &count);
		}
		i++;
	}
	va_end(args);
	return (count.len);
}

/*
#include <stdio.h>
int	main(void)
{
	char *str = 0;
	printf("\n%d\n", ft_printf(" %p %p ", str, str));
	printf(" %p %p ", str, str);
}
*/

/* In a typical printf implementmation, the return value 
represents the number of characters printed. Value of 
the length is stored in a struct t_struct. */

/*• %c Prints a single character.
• %s Prints a string (as defined by the common C convention).
• %p The void * pointer argument has to be printed in hexadecimal format.
• %d Prints a decimal (base 10) number.
• %i Prints an integer in base 10.
• %u Prints an unsigned decimal (base 10) number.
• %x Prints a number in hexadecimal (base 16) lowercase format.
• %X Prints a number in hexadecimal (base 16) uppercase format.
• %% Prints a percent sign.*/
