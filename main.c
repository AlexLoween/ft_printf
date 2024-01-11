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

int ft_conversion(char *param, va_list argunment, int len)
{
    if(*param == 'c')
        ft_putchar(va_arg(argunment, int), &len);
    else if(*param == 's')
    ;//TODO
    else if (*param == 'p')
    ;    //TODO
    else if(*param == 'i' || *param == 'd')
    ;    //TODO
    else if(*param == 'x')
    ;    //TODO
    else if (*param == 'X')
    ;    //TODO
    else if (*param == 'u')
    ;    //TODO
    else if (*param == '%')
    ;    //TODO
    else 
        return (1);
    return(len);        
}

int ft_printf(char const *param, ...)
{
    int len;
    va_list argument;
    
    va_start(argument, param);
    len = 0;

    while(*param)
    {
        if(*param == '%')
        {
            param++;
            len += ft_conversion(param,argument,&len);
        }
        else
            len += write(1,param, 1);
        param++;     
    }
    va_end(argument);
    return(len);
}


int main()
{
    printf( "%c", 'h');
    ft_printf("%c", 'h');
}