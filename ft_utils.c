/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madumerg <madumerg@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 11:39:23 by madumerg          #+#    #+#             */
/*   Updated: 2024/02/18 14:58:46 by madumerg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_verif_double(t_stack **stack)
{
	t_stack	*pos;
	t_stack	*verif_all;

	pos = (*stack);
	while (pos)
	{
		verif_all = pos->next;
		while (verif_all)
		{
			if (verif_all->content == pos->content)
				return (-1);
			verif_all = verif_all->next;
		}
		pos = pos->next;
	}
	return (0);
}

int	ft_is_sort(t_stack **stack)
{
	t_stack	*temp;

	temp = (*stack);
	while (temp->next && temp->content < temp->next->content)
		temp = temp->next;
	if (temp->next == NULL)
		return (-1);
	return (0);
}
