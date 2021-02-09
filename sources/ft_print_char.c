/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codecham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 05:02:00 by codecham          #+#    #+#             */
/*   Updated: 2021/01/28 05:02:01 by codecham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_print_char(int c, t_flags flags)
{
	int char_count;

	char_count = 0;
	if (flags.width > 1)
	{
		if (flags.minus == 0)
		{
			char_count += ft_flags_display(flags.width, 1, 0);
			char_count += ft_putchar(c);
		}
		else
		{
			char_count += ft_putchar(c);
			char_count += ft_flags_display(flags.width, 1, 0);
		}
	}
	else
		char_count += ft_putchar(c);
	return (char_count);
}
