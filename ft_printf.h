/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexlowen <alexlowen@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:33:41 by alexlowen         #+#    #+#             */
/*   Updated: 2024/01/11 19:40:49 by alexlowen        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdio.h>  //para utilizar printf
#include <unistd.h> // para utilizar el write
#include <stdarg.h> //para las funciones variadicas

int ft_putchar(int c);
int ft_putstr(char *s);

#endif