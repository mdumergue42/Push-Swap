/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madumerg <madumerg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:41:05 by madumerg          #+#    #+#             */
/*   Updated: 2023/11/09 16:18:08 by madumerg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t ct, size_t size)
{
	char	*str;

	if (size == 0 || ct == 0)
		return (malloc(1));
	if ((int)size < 0 && (int)ct < 0)
		return (NULL);
	if ((unsigned long long)(size * ct) > UINT_MAX)
		return (NULL);
	str = malloc(size * ct);
	if (!str)
		return (NULL);
	ft_bzero(str, size * ct);
	return (str);
}
