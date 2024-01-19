/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexlowen <alexlowen@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:32:45 by alexlowen         #+#    #+#             */
/*   Updated: 2024/01/18 15:39:13 by alexlowen        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

 void ft_format(char format, va_list args, int *len)
 {

	if (format == 's')
				ft_putstr(va_arg(args, char *), len);
			else if (format == 'd' || format == 'i')
				ft_putnbr((long long int)va_arg(args, int), len, 10);
			else if (format == 'x')
				ft_putnbr((long long int)va_arg(args, unsigned), len, 16);
            else if (format == 'X')
				ft_putnbrx((long long int)va_arg(args, unsigned), len, 16);
            else if (format == 'u')
				ft_putnbru((unsigned long int)va_arg(args, unsigned), len, 10);
            else if (format == 'c')
                ft_putchar(va_arg(args, int), len);
            else if(format == '%')
                ft_percent(va_arg(args, int), len);
            else if (format == 'p')
            {
                ft_putstr("0x", len);
                ft_pointer(va_arg(args, unsigned long long), len, 16);
            }
 }



int	ft_printf(const char *format, ...)
{
	va_list	args;
	int	len;


	len = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			ft_format(*format,args, &len);
			
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
    int original;
    int mio;

    mio = ft_printf("%p", (void *)-1);
    original = printf("%p", (void *)-1);

    printf("original %d\n mio %d\n",original , mio);
 
}*/