/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codecham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 11:36:13 by codecham          #+#    #+#             */
/*   Updated: 2020/03/05 16:04:22 by codecham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*tmp_src;
	unsigned char	*tmp_dst;

	if (!dst || !src)
		return (0);
	i = 0;
	tmp_src = (unsigned char *)src;
	tmp_dst = (unsigned char *)dst;
	while (i < n && (unsigned char)tmp_src[i] != (unsigned char)c)
	{
		tmp_dst[i] = tmp_src[i];
		i++;
	}
	if (i == n)
		return (NULL);
	tmp_dst[i] = tmp_src[i];
	return (&tmp_dst[i + 1]);
}
