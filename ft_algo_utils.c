/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madumerg <madumerg@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 18:25:38 by madumerg          #+#    #+#             */
/*   Updated: 2024/02/19 12:45:13 by madumerg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_nb_of_mov(int pos, int size)
{
	if (size - pos < pos)
		return (size - pos);
	return (pos);
}

void	ft_bis_best_m(int i_min_mov_b, int size_b, t_stack **stack_b)
{
	if (i_min_mov_b < (size_b / 2))
	{
		while (stack_b && *stack_b && i_min_mov_b > 0)
		{
			ft_rotate_b(stack_b);
			i_min_mov_b--;
		}
	}
	else
	{
		while (stack_b && *stack_b && i_min_mov_b < size_b)
		{
			ft_reverse_rotate_b(stack_b);
			i_min_mov_b++;
		}
	}
}

int	ft_search_the_place(t_stack **stack_a, int nb)
{
	t_stack	*temp;
	int		i;

	i = 0;
	temp = (*stack_a);
	while (temp && temp->next)
	{
		if (temp->content < nb && temp->next->content > nb)
			return (i + 1);
		temp = temp->next;
		i++;
	}
	if (temp && (*stack_a) && nb > temp->content && nb < (*stack_a)->content)
		return (0);
	return (ft_find_min(stack_a));
}
