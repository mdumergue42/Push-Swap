/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madumerg <madumerg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:42:26 by madumerg          #+#    #+#             */
/*   Updated: 2023/11/03 14:21:31 by madumerg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	sdst;
	size_t	ssrc;
	size_t	i;
	size_t	j;

	sdst = ft_strlen(dest);
	ssrc = ft_strlen(src);
	i = 0;
	j = sdst;
	if (sdst > size || size == 0)
		return (ssrc + size);
	while (src[i] && (i < size) && (sdst < size - 1))
	{
		dest[sdst] = src[i];
		i++;
		sdst++;
	}
	dest[sdst] = '\0';
	return (ssrc + j);
}
