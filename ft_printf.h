/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexlowen <alexlowen@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:33:41 by alexlowen         #+#    #+#             */
/*   Updated: 2024/01/23 21:49:14 by ralanes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>  //para utilizar printf
# include <unistd.h> // para utilizar el write
# include <stdarg.h> //para las funciones variadicas
# include <limits.h>

void	ft_putstr(char *str, int *len);
void	ft_putnbr(long long int nbr, int *len, int base);
void	ft_putchar(int c, int *len);
void	ft_putnbrx(long long int nbr, int *len, int base);
void	ft_putnbru(unsigned long int nbr, int *len, unsigned int base);
void	ft_pointer(unsigned long int nbr, int *len, unsigned int base);
int		ft_printf(const char *format, ...);
void	ft_handle_format(char format, va_list args, int *len);
void	ft_format(char format, va_list args, int *len);

#endif