/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexlowen <alexlowen@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 19:36:57 by alexlowen         #+#    #+#             */
/*   Updated: 2024/01/18 15:29:48 by alexlowen        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_putchar(int c)
{
    int len;

    len = 0;
    len += write(1,&c, 1);
    return(len);
}
int ft_putstr(char *s)
{
    int len;
    int i;

    len = 0;
    i = 0;
    while(s[i])
    {
        len +=ft_putchar(s[i]);
        i++;
    }
    return(len);
}
int ft_putnbr(int n)
{
    if(n == -2147483648)
    {   
        ft_putchar('-');                                                                                            
        ft_putchar('2');
        ft_putchar(147483648);
    }
    else if(n < 0)
    {
        ft_putchar('-');
        ft_putchar(-n);
    }
    else if(n > 9)
    {
        ft_putnbr(n/10);
        ft_putnbr(n%10);
    }
    else
        ft_putchar(n + '0');
return(n);
}
