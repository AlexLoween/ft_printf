/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexlowen <alexlowen@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:32:45 by alexlowen         #+#    #+#             */
/*   Updated: 2024/01/11 19:11:31 by alexlowen        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
        }
        else
            len += write(1,param, 1);
        param++;     
    }
    va_end(argument);
    return(len);
}

int main ()
{
    printf( "hello world/n");
    ft_printf("hello worrd");
}