/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madumerg <madumerg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:33:52 by madumerg          #+#    #+#             */
/*   Updated: 2023/11/07 17:51:00 by madumerg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	len;
	char	*str;

	if (!s1)
		return (NULL);
	len = ft_strlen(s1);
	start = 0;
	while (ft_strchr(set, s1[start]) != 0)
		start++;
	while (ft_strrchr(set, s1[len]) != 0)
		len--;
	str = ft_substr(s1, start, (len - start) + 1);
	return (str);
}
