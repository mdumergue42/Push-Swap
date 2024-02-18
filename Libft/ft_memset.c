/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madumerg <madumerg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:42:15 by madumerg          #+#    #+#             */
/*   Updated: 2023/11/02 14:11:59 by madumerg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int v, size_t count)
{
	size_t	i;

	i = 0;
	while (i != count)
	{
		*(unsigned char *)(ptr + i) = (unsigned char)v;
		i++;
	}
	return (ptr);
}
