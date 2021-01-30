/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_hexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codecham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 05:01:56 by codecham          #+#    #+#             */
/*   Updated: 2021/01/29 02:00:07 by codecham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int          ft_calcul_size(long n)
{
    int i;

    i = 0;
    while (n/16 != 0)
    {
        n /= 16;
        i++;
    }
    i++;
    return(i);
}

static char         *ft_convert_hexa(long n, char *base)
{
    int i;
    char *str;

    i = ft_calcul_size(n);
    if (!(str = (char *)malloc(sizeof(char) * (i + 1))))
	    return (NULL);
    str[i] = '\0';
    i--;
    while (n/16 != 0 && n != 0)
    {
        str[i] = base[n%16];
        n /= 16;
        i--;
    }
    str[i] = base[n];
    return(str);
}

static void         ft_fill_base(char *base, int type)
{
    int i;
    char c;

    i = 0;
    c = '0';
    while (i < 10)
    {
        base[i] = c;
        c++;
        i++;
    }
    if (type == 0)
        c = 'a';
    else
        c = 'A';
    while (i < 16)
    {
        base[i] = c;
        c++;
        i++;
    }
    base[i] = '\0';
}

char                *ft_itoa_hexa(unsigned long long nbr, int type)
{
    char base[17];
    char *str;

    if (nbr == 0)
    {
        if (!(str = (char *)malloc(sizeof(char) * 2)))
	        return (NULL);
        str[0] = '0';
        str[1] = '\0';
        return (str);
    }
    ft_fill_base(base, type);
    str = ft_convert_hexa(nbr, base);
    return(str);
}