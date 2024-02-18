/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specific_mov.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madumerg <madumerg@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 12:44:21 by madumerg          #+#    #+#             */
/*   Updated: 2024/02/18 18:08:55 by madumerg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_specific_mov_for_three_nb(t_stack **stack)
{
	if (ft_find_max(stack) == 0)
	{
		ft_rotate_a(stack);
		if (ft_is_sort(stack) == 0)
			ft_swap_a(stack);
	}
	else if (ft_find_max(stack) == 1)
	{
		ft_reverse_rotate_a(stack);
		if (ft_is_sort(stack) == 0)
			ft_swap_a(stack);
	}
	else if (ft_find_max(stack) == 2)
		ft_swap_a(stack);
	return ;
}

void	ft_sort_four(t_stack **stack, t_stack **stack_b)
{
	if (ft_find_min(stack) == 0)
		ft_push_b(stack, stack_b);
	else if (ft_find_min(stack) == 1)
	{
		ft_swap_a(stack);
		ft_push_b(stack, stack_b);
	}
	else if (ft_find_min(stack) == 2)
	{
		ft_rotate_a(stack);
		ft_swap_a(stack);
		ft_push_b(stack, stack_b);
	}
	else if (ft_find_min(stack) == 3)
	{
		ft_reverse_rotate_a(stack);
		ft_push_b(stack, stack_b);
	}
}

void	ft_sort_five(t_stack **stack, t_stack **stack_b)
{
	if (ft_find_min(stack) == 0)
		ft_push_b(stack, stack_b);
	else if (ft_find_min(stack) == 1)
	{
		ft_swap_a(stack);
		ft_push_b(stack, stack_b);
	}
	else if (ft_find_min(stack) == 2)
	{
		ft_rotate_a(stack);
		ft_swap_a(stack);
		ft_push_b(stack, stack_b);
	}
	else if (ft_find_min(stack) == 3)
	{
		ft_reverse_rotate_a(stack);
		ft_reverse_rotate_a(stack);
		ft_push_b(stack, stack_b);
	}
	else if (ft_find_min(stack) == 4)
	{
		ft_reverse_rotate_a(stack);
		ft_push_b(stack, stack_b);
	}
}

void	ft_specific_mov_for_five_nb(t_stack **stack, t_stack **stack_b)
{
	ft_sort_five(stack, stack_b);
	ft_sort_four(stack, stack_b);
	if (ft_is_sort(stack) == 0)
		ft_specific_mov_for_three_nb(stack);
	ft_push_a(stack, stack_b);
	ft_push_a(stack, stack_b);
}

void	ft_specific_mov(t_stack **stack, t_stack **stack_b)
{
	if (ft_stack_size(*stack) == 2)
	{
		ft_swap_a(stack);
		ft_stack_clear(stack);
		exit (1);
	}
	else if (ft_stack_size(*stack) == 3)
	{
		ft_specific_mov_for_three_nb(stack);
		ft_stack_clear(stack);
		exit (1);
	}
	else if (ft_stack_size(*stack) == 5)
	{
		ft_specific_mov_for_five_nb(stack, stack_b);
		ft_stack_clear(stack);
		ft_stack_clear(stack_b);
		exit (1);
	}
}
