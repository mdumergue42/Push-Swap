/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madumerg <madumerg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:14:32 by madumerg          #+#    #+#             */
/*   Updated: 2023/11/08 10:22:00 by madumerg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(int n)
{
	int				cpt;
	unsigned int	nb;

	cpt = 0;
	if (n < 0)
	{
		cpt++;
		nb = -n;
	}
	else
		nb = n;
	while (nb >= 10)
	{
		nb /= 10;
		cpt++;
	}
	cpt++;
	return (cpt);
}

char	*ft_itoa(int n)
{
	char			*str;
	int				cpt;
	long long int	nb;
	int				i;

	i = 0;
	nb = n;
	cpt = ft_len(n);
	str = ft_calloc((cpt + 1), sizeof(char));
	if (!str)
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		i = 1;
		nb *= -1;
	}
	cpt--;
	while (cpt >= i)
	{
		str[cpt] = (nb % 10) + '0';
		nb /= 10;
		cpt--;
	}
	return (str);
}
