/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madumerg <madumerg@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:11:42 by madumerg          #+#    #+#             */
/*   Updated: 2024/02/22 10:35:30 by madumerg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_hexa_low(size_t n)
{
	size_t	i;

	i = 0;
	if (n < 16)
	{
		i += ft_putchar("0123456789abcdef"[n % 16]);
		return (i);
	}
	else if (n >= 10)
	{
		i += ft_putnbr_hexa_low(n / 16);
		i += ft_putnbr_hexa_low(n % 16);
	}
	return (i);
}

int	ft_putnbr_hexa_upp(unsigned int n)
{
	unsigned int	i;

	i = 0;
	if (n < 16)
	{
		i += ft_putchar("0123456789ABCDEF"[n % 16]);
		return (i);
	}
	else if (n >= 10)
	{
		i += ft_putnbr_hexa_upp(n / 16);
		i += ft_putnbr_hexa_upp(n % 16);
	}
	return (i);
}

int	ft_print_ptr(void *ptr)
{
	int	i;

	if (!ptr)
		i = ft_putstr("(nil)");
	else
		i = ft_putstr("0x") + ft_putnbr_hexa_low((size_t)ptr);
	return (i);
}
