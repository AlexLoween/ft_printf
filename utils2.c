/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralanes <ralanes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 19:36:57 by alexlowen         #+#    #+#             */
/*   Updated: 2024/03/05 20:07:13 by ralanes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbrx(long long int nbr, int *len, int base)
{
	char	*hex;

	hex = "0123456789ABCDEF";
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
		ft_putnbrx((nbr / base), len, base);
	*len += write(1, &hex[nbr % base], 1);
}

void	ft_putnbru(unsigned long int nbr, int *len, unsigned int base)
{
	char	*base1;

	base1 = "0123456789";
	if (nbr >= base)
		ft_putnbru((nbr / base), len, base);
	*len += write(1, &base1[nbr % base], 1);
}

void	ft_pointer(unsigned long int nbr, int *len, unsigned int base)
{
	char	*hex;

	if (nbr == ULLONG_MAX)
	{
		*len += write(1, "ffffffffffffffff", 16);
		return ;
	}
	hex = "0123456789abcdef";
	if (nbr >= base)
		ft_pointer((nbr / base), len, base);
	*len += write(1, &hex[nbr % base], 1);
}
