/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pourcent.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codecham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 23:20:53 by codecham          #+#    #+#             */
/*   Updated: 2021/01/28 23:23:22 by codecham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int     ft_print_pourcent(t_flags flags)
{
	int char_count;

	char_count = 0;
	if (flags.minus == 1)
		char_count += ft_putstrn("%", 1);
	char_count += ft_flags_display(flags.width, 1, flags.zero);
	if (flags.minus == 0)
		char_count += ft_putstrn("%", 1);
	return (char_count);
}