/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexlowen <alexlowen@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 19:36:57 by alexlowen         #+#    #+#             */
/*   Updated: 2024/01/22 20:49:05 by ralanes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(int c, int *len)
{
	*len += write(1, &c, 1);
}

void	ft_putstr(char *str, int *len)
{
	if (!str)
		str = "(null)";
	while (*str)
		*len += write(1, str++, 1);
}

void	ft_putnbr(long long int nbr, int *len, int base)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (nbr == INT_MIN)
	{
		*len += write(1, "-2147483648", 11);
		return ;
	}
	if (nbr < 0)
	{
		nbr *= -1;
		*len += write(1, "-", 1);
	}
	if (nbr >= base)
		ft_putnbr((nbr / base), len, base);
	*len += write(1, &hex[nbr % base], 1);
}
