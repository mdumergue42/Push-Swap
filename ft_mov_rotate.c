/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mov_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madumerg <madumerg@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 13:18:05 by madumerg          #+#    #+#             */
/*   Updated: 2024/02/18 14:58:17 by madumerg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stack_rotate(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*last;

	if (!stack || !(*stack))
		return ;
	temp = (*stack)->next;
	last = ft_stack_last(*stack);
	last->next = (*stack);
	(*stack)->next = NULL;
	(*stack) = temp;
}

void	ft_rotate_a(t_stack **stack_a)
{
	if (!stack_a || !(*stack_a) || !(*stack_a)->next)
		return ;
	ft_stack_rotate(stack_a);
	ft_printf("ra\n");
}

void	ft_rotate_b(t_stack **stack_b)
{
	if (!stack_b || !(*stack_b) || !(*stack_b)->next)
		return ;
	ft_stack_rotate(stack_b);
	ft_printf("rb\n");
}

void	ft_rotate_rr(t_stack **stack_a, t_stack **stack_b)
{
	if (!stack_a || !(*stack_a) || !(*stack_a)->next)
	{
		ft_rotate_b(stack_b);
		return ;
	}
	ft_stack_rotate(stack_a);
	ft_stack_rotate(stack_b);
	ft_printf("rr\n");
}
