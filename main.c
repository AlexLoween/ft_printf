/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexlowen <alexlowen@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:32:45 by alexlowen         #+#    #+#             */
/*   Updated: 2024/01/11 19:45:23 by alexlowen        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_conversion(char c, va_list argument)
{
    if(c == 'c')
        return(ft_putchar(va_arg(argument, int)));
    else if(c == 's')
        return(ft_putstr(va_arg(argument, char *)));
    else if (c == 'p')
    ;    //TODO
    else if(c == 'i' || c == 'd')
    ;    //TODO
    else if(c == 'x')
    ;    //TODO
    else if (c == 'X')
    ;    //TODO
    else if (c == 'u')
    ;    //TODO
    else if (c == '%')
       return (write(1,"%%",1));   
    return (0);      
}

int ft_printf(char const *param, ...)
{
    int len;
    int p;
    va_list argument;
    
    va_start(argument, param);
    len = 0;
    p = 0;
    while(param[p])
    {
        if(param[p] == '%')
        {
            len += ft_conversion(param[p+1],argument);
            p++;
        }
        else
            len += write(1,&param[p], 1);
        p++;     
    }
    va_end(argument);
    return(len);
}


int main()
{
    printf( "%s", "hola");
    ft_printf("%s", "hola");


}