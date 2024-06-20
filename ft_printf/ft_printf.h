/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srudman <srudman@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 19:22:05 by srudman           #+#    #+#             */
/*   Updated: 2023/07/29 20:45:53 by srudman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>

typedef struct s_struct
{
	int	len;
}	t_struct;

void	ft_putchar(char c, t_struct *count);
void	ft_putnbr(int n, t_struct *count);
void	ft_puthex(unsigned int nbr, t_struct *count, char *base);
void	ft_putstr(char *s, t_struct *count);
void	ft_putdecimal(unsigned int nbr, t_struct *count);
int		ft_printf(const char *str, ...);
void	ft_putpointer(void *ptr, t_struct *count);

#endif
