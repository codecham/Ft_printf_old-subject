/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_display.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codecham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 05:01:35 by codecham          #+#    #+#             */
/*   Updated: 2021/01/28 05:01:40 by codecham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int     ft_flags_display(int size, int minus, int type)
{
    int i;

    i = 0;
    while (size - minus > 0)
    {
        if(type == 1)
            ft_putchar('0');
        else
            ft_putchar(32);
        size--;
        i++;
    }
    return (i);
}