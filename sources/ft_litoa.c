/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_litoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codecham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 21:07:13 by codecham          #+#    #+#             */
/*   Updated: 2021/02/02 21:10:36 by codecham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		ft_size(long nb)
{
	int	i;

	i = 1;
	if (nb < 0)
		i++;
	while (nb / 10)
	{
		i++;
		nb = nb / 10;
	}
	return (i);
}

static void		ft_fill_tab(char *tab, long div, long nb, int i)
{
	while (div)
	{
		tab[i] = (nb / div) + '0';
		nb = nb % div;
		div = div / 10;
		i++;
	}
	tab[i] = '\0';
}

char			*ft_litoa(long nb)
{
	int		size;
	int		i;
	long	div;
	char	*tab;

	size = ft_size(nb);
	i = 0;
	div = 1;
	if (!(tab = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	if (nb < 0)
	{
		tab[i] = '-';
		i++;
		nb = nb * -1;
	}
	while (nb / div > 9)
		div = div * 10;
	ft_fill_tab(tab, div, nb, i);
	return (tab);
}
