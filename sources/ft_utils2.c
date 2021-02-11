/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codecham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 05:02:32 by codecham          #+#    #+#             */
/*   Updated: 2021/02/11 16:24:38 by codecham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_putstrn(char *str, int n)
{
	int i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i] && i < n)
		ft_putchar(str[i++]);
	return (i);
}
