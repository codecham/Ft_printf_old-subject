/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codecham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 15:04:56 by codecham          #+#    #+#             */
/*   Updated: 2020/03/05 15:26:08 by codecham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*tmp_s;

	if (!s || n <= 0)
		return (0);
	i = 0;
	tmp_s = (char *)s;
	while (i < n)
	{
		if (tmp_s[i] == c)
			return (&tmp_s[i]);
		i++;
	}
	return (0);
}
