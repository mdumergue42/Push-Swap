/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_median.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madumerg <madumerg@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 13:47:51 by madumerg          #+#    #+#             */
/*   Updated: 2024/02/29 09:36:04 by madumerg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_quarter(t_stack **stack, int nb)
{
	t_stack	*temp;
	int		cpt;

	temp = (*stack);
	cpt = 0;
	while (temp)
	{
		if (temp->content > nb)
			cpt++;
		if (temp->content < nb)
			cpt -= 3;
		temp = temp->next;
	}
	if (cpt == 0 || cpt == 1 || cpt == -1)
		return (1);
	return (0);
}

int	ft_quarter(t_stack **stack)
{
	t_stack	*temp;

	temp = (*stack);
	while (temp)
	{
		if (ft_is_quarter(stack, temp->content) == 1)
			return (temp->content);
		temp = temp->next;
	}
	return (0);
}

int	ft_is_median(t_stack **stack, int nb)
{
	t_stack	*temp;
	int		cpt;

	temp = (*stack);
	cpt = 0;
	while (temp)
	{
		if (temp->content > nb)
			cpt++;
		if (temp->content < nb)
			cpt--;
		temp = temp->next;
	}
	if (cpt == 0 || cpt == 1 || cpt == -1)
		return (1);
	return (0);
}

int	ft_median(t_stack **stack)
{
	t_stack	*temp;

	temp = (*stack);
	while (temp)
	{
		if (ft_is_median(stack, temp->content) == 1)
			return (temp->content);
		temp = temp->next;
	}
	return (0);
}
