/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codecham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 05:02:12 by codecham          #+#    #+#             */
/*   Updated: 2021/01/28 05:02:13 by codecham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_display_pointer(char *str, t_flags flags)
{
	int char_count;

	char_count = 0;
	char_count += ft_putstrn("0x", 2);
	if (flags.dot >= 0)
	{
		char_count += ft_flags_display(flags.dot, ft_strlen(str), 1);
		char_count += ft_putstrn(str, flags.dot);
	}
	else
		char_count += ft_putstrn(str, ft_strlen(str));
	return (char_count);
}


int			ft_print_pointer(unsigned long long p, t_flags flags)
{
    char *str;
    int char_count;

    if (flags.dot == 0 && p == 0)
    {
        char_count += ft_putstrn("0x", 2);
		return (char_count += ft_flags_display(flags.width, 0, 1));
    }
    str = ft_itoa_hexa(p, 0);
    if ((size_t)flags.dot < ft_strlen(str))
		flags.dot = ft_strlen(str);
    if (flags.minus == 1)
        char_count += ft_display_pointer(str, flags);
	char_count += ft_flags_display(flags.width, ft_strlen(str) + 2, 0);
	if (flags.minus == 0)
		char_count += ft_display_pointer(str, flags);
	free(str);
	return (char_count);

}