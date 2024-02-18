/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madumerg <madumerg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:14:46 by madumerg          #+#    #+#             */
/*   Updated: 2023/11/09 16:14:35 by madumerg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_len(const char *str, char s)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (str[i] && str[i] != s)
	{
		len++;
		i++;
	}
	return (len);
}

static int	ft_count_w(const char *str, char s)
{
	int	i;
	int	cpt;

	i = 0;
	cpt = 0;
	if (!*str)
		return (0);
	if (str[i++] != s)
		cpt++;
	while (str[i])
	{
		if (str[i - 1] == s && str[i] != s)
			cpt++;
		i++;
	}
	return (cpt);
}

static void	*ft_free(char **s)
{
	size_t	size;

	size = 0;
	while (s[size])
	{
		free(s[size]);
		size++;
	}
	free(s);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		letter;
	int		word;
	int		tab;

	word = 0;
	tab = 0;
	if (!s)
		return (NULL);
	str = ft_calloc(sizeof(char *), (ft_count_w(s, c) + 1));
	if (!str)
		return (NULL);
	while (word < ft_count_w(s, c))
	{
		while (s[tab] == c)
			tab++;
		letter = ft_count_len(s + tab, c);
		str[word] = ft_calloc(sizeof(char), letter + 1);
		if (!str[word])
			return (ft_free(str));
		ft_strlcpy(str[word], s + tab, letter + 1);
		word++;
		tab += letter;
	}
	return (str);
}
