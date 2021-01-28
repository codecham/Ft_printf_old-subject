/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codecham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 05:02:16 by codecham          #+#    #+#             */
/*   Updated: 2021/01/28 05:02:17 by codecham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int     ft_treat_string(char *str, int size, t_flags flags)
{
        int char_count;

        char_count = 0;
        if (flags.minus == 0)
        {
            char_count += ft_flags_display(flags.width, size, 0);
            char_count += ft_putstr(str);
        }
        else
        {
            char_count += ft_putstr(str);
            char_count += ft_flags_display(flags.width, size, 0);
        }
        return (char_count);
}

int     ft_print_string(char *str, t_flags flags)
{
        int char_count;
        int size;

        char_count = 0;
        size = strlen(str);
        if (flags.dot < size && flags.dot > 0)
            char_count += ft_putstrn(str, flags.dot);
        else if (flags.width > size)
            char_count += ft_treat_string(str, size, flags);
        else
            char_count += ft_putstr(str);
        return (char_count);
}