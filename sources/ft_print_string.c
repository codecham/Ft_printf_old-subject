/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codecham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 05:02:16 by codecham          #+#    #+#             */
/*   Updated: 2021/01/29 18:29:44 by codecham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		ft_display_str(char *str, t_flags flags)
{
	int char_count;

	char_count = 0;
	if (flags.dot >= 0)
	{
		char_count += ft_flags_display(flags.dot, ft_strlen(str), 0);
		char_count += ft_putstrn(str, flags.dot);
	}
	else
	{
		char_count += ft_putstrn(str, ft_strlen(str));
	}
	return (char_count);
}

int				ft_print_string(char *str, t_flags flags)
{
	int char_count;

	char_count = 0;
	if (!str)
		str = "(null)";
	if (flags.dot >= 0 && (size_t)flags.dot > ft_strlen(str))
		flags.dot = ft_strlen(str);
	if (flags.minus == 1)
		char_count += ft_display_str(str, flags);
	if (flags.dot >= 0)
		char_count += ft_flags_display(flags.width, flags.dot, 0);
	else
		char_count += ft_flags_display(flags.width, ft_strlen(str), 0);
	if (flags.minus == 0)
		char_count += ft_display_str(str, flags);
	return (char_count);
}
