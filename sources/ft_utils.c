/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codecham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 05:02:26 by codecham          #+#    #+#             */
/*   Updated: 2021/01/28 05:02:27 by codecham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int     ft_putchar(int c)
{
    ft_putchar_fd(c, 1);
    return(1);
}

int     ft_char_to_int(char c)
{  
    return(c - 48);
}

int     ft_flags_list(char c)
{
    if(c == '0' || c == '-' || c == '.' || c == '*')
        return(1);
    else if(c >= '1' && c <= '9')
        return(1);
    else
        return(-1);

}  

int     ft_type_list(char c)
{
    if(c == 'd' || c == 'i' || c == 'u' || c == 'p' || c == 'x' || c == 'X' || c == 'c' || c == 's' || c == '%')
        return(1);
    else
        return(0);
}
int     ft_putstr(char *str)
{
    int i = 0;

    while(str[i])
    {
        ft_putchar(str[i]);
        i++;
    }
    return(i);
}
