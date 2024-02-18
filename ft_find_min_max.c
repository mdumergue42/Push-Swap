/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_min_max.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madumerg <madumerg@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 12:56:52 by madumerg          #+#    #+#             */
/*   Updated: 2024/02/18 18:24:19 by madumerg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_find_max(t_stack **stack)
{
	t_stack	*temp;
	int		max;
	int		pos;
	int		i;

	i = 0;
	pos = 0;
	max = -2147483648;
	temp = (*stack);
	while (temp)
	{
		if (max < temp->content)
		{
			max = temp->content;
			pos = i;
		}
		temp = temp->next;
		i++;
	}
	return (pos);
}

int	ft_find_min(t_stack **stack)
{
	t_stack	*temp;
	int		min;
	int		pos;
	int		i;

	i = 0;
	pos = 0;
	min = 2147483647;
	temp = (*stack);
	while (temp)
	{
		if (min > temp->content)
		{
			min = temp->content;
			pos = i;
		}
		temp = temp->next;
		i++;
	}
	return (pos);
}
