/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codecham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 05:01:49 by codecham          #+#    #+#             */
/*   Updated: 2021/02/10 17:21:35 by codecham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			ft_flag(const char *input, int i, t_flags *flags, va_list args)
{
	while (input[i])
	{
		if (!ft_isdigit(input[i]) && !ft_flags_list(input[i])
		&& !ft_type_list(input[i]))
			break ;
		if (input[i] == '0' && flags->width == 0 && flags->minus == 0)
			flags->zero = 1;
		if (input[i] == '.')
			i = ft_flag_dot(input, i, flags, args);
		if (input[i] == '-')
			*flags = ft_flag_minus(*flags);
		if (input[i] == '*')
			*flags = ft_flag_width(args, *flags);
		if (ft_isdigit(input[i]))
			*flags = ft_flag_digit(input[i], *flags);
		if (ft_type_list(input[i]))
		{
			flags->type = input[i];
			break ;
		}
		i++;
	}
	return (i);
}
