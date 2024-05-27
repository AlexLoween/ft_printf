/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralanes <ralanes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:32:45 by alexlowen         #+#    #+#             */
/*   Updated: 2024/05/27 20:33:44 by ralanes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_handle_format(char format, va_list args, int *len)
{
	if (format == 's')
		ft_putstr(va_arg(args, char *), len);
	else if (format == 'd' || format == 'i')
		ft_putnbr((long long int)va_arg(args, int), len, 10);
	else if (format == 'x')
		ft_putnbr(va_arg(args, unsigned), len, 16);
	else if (format == 'X')
		ft_putnbrx(va_arg(args, unsigned), len, 16);
	else if (format == 'u')
		ft_putnbru(va_arg(args, unsigned), len, 10);
	else if (format == 'c')
		ft_putchar((char)va_arg(args, int), len);
	else if (format == '%')
		*len += write(1, "%%", 1);
	else
		*len += write(1, &format, 1);
}

void ft_format(char format, va_list args, int *len) {
    if (format == 'p')
	{
        void *ptr = va_arg(args, void *);
        if (ptr == NULL)
			ft_putstr("(nil)", len);
	else
	{
		ft_putstr("0x", len);
		ft_pointer((size_t)ptr, len, 16);
	}
	else
		ft_handle_format(format, args, len);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		len;

	len = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			ft_format(*format, args, &len);
		}
		else
			len += write(1, format, 1);
		format++;
	}
	va_end(args);
	return (len);
}

/*int main()
{
	int mio;
	int original;
	
	mio = ft_printf("%x %%hola%p\n", -42, NULL);
	original = printf("%x %%hola%p\n", -42, NULL);
	
	printf("mio %d\noriginal %d\n",mio ,original);
}*/