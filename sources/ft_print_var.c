/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_var.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codecham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 05:02:21 by codecham          #+#    #+#             */
/*   Updated: 2021/01/28 23:22:57 by codecham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int     ft_print_var(char type, t_flags flags, va_list args)
{
        int char_count;

        char_count = 0;
        if (type == 'd' || type == 'i')
            char_count = ft_print_int(va_arg(args, int), flags);
        if (type == 'c')
            char_count = ft_print_char(va_arg(args, int), flags);
        if (type == 's')
            char_count = ft_print_string(va_arg(args, char *), flags);
        if (type == 'x')
            char_count = ft_print_hexa(va_arg(args, unsigned int), 0, flags);
        if (type == 'X')
            char_count = ft_print_hexa(va_arg(args, unsigned int), 1, flags);
        if (type == 'p')
            char_count = ft_print_pointer(va_arg(args, unsigned long long), flags);
        if (type == 'u')
            char_count = ft_print_unsigned_int(va_arg(args, unsigned int), flags);
        if (type == '%')
            char_count = ft_print_pourcent(flags);
            
    return(char_count);
}