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

void	ft_format(char format, va_list args, int *len)
{
	void	*ptr;

	if (format == 'p')
	{
		ptr = va_arg(args, void *);
		if (ptr == NULL)
			ft_putstr("(nil)", len);
		else
		{
			ft_putstr("0x", len);
			ft_pointer((size_t)ptr, len, 16);
		}
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
	char			*str;
	char			c;
	int 	x;
	void	 *ptr;

	c = 'a';
	str = "Unicorns dose not exists";
	x = 123;
	ptr = &x;

	printf("MIO: %d\n", ft_printf("El caracter es %p \n",NULL));
	printf("Original: %d\n", printf("El caracter es %p \n", NULL));
	printf("MIO: %d\n", ft_printf("El caracter es %c\n", c));
	printf("Original: %d\n", printf("El caracter es %c\n", c));
	printf("MIO: %d\n", ft_printf("String: %s\n", str));
	printf("Original: %d\n", printf("String: %s\n", str));
	printf("MIO: %d\n", ft_printf("Puntero: %p\n", ptr));
	printf("Original: %d\n", printf("Puntero: %p\n", ptr));
	printf("MIO: %d\n", ft_printf("Int max: %d, Int min: %i\n",0, -2147483648));
	printf("Origi: %d\n", printf("Int max: %d, Int min: %li\n",0, -2147483648));
	printf("MIO: %d\n", ft_printf("Unsigned int: %u\n", 4294967295));
	printf("Original: %d\n", printf("Unsigned int: %lu\n", 4294967295));
	printf("MIO: %d\n", ft_printf("Hexadecimal en minuscula: %x\n", 255));
	printf("Original: %d\n", printf("Hexadecimal en minuscula: %x\n", 255));

}*/