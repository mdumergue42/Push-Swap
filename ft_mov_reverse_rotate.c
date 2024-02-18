/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mov_reverse_rotate.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madumerg <madumerg@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 13:17:43 by madumerg          #+#    #+#             */
/*   Updated: 2024/02/18 18:24:53 by madumerg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_stack_before_last(t_stack *stack)
{
	t_stack	*temp;

	temp = stack;
	if (!stack)
		return (NULL);
	while (temp->next)
	{
		if (temp->next->next == NULL)
			return (temp);
		temp = temp->next;
	}
	return (temp);
}

void	ft_reverse_rotate_stack(t_stack **stack)
{
	t_stack	*before;
	t_stack	*last;

	if (!stack || !(*stack))
		return ;
	last = ft_stack_last(*stack);
	before = ft_stack_before_last(*stack);
	before->next = NULL;
	last->next = (*stack);
	(*stack) = last;
}

void	ft_reverse_rotate_a(t_stack **stack_a)
{
	if (!stack_a || !(*stack_a) || !(*stack_a)->next)
		return ;
	ft_reverse_rotate_stack(stack_a);
	ft_printf("rra\n");
}

void	ft_reverse_rotate_b(t_stack **stack_b)
{
	if (!stack_b || !(*stack_b) || !(*stack_b)->next)
		return ;
	ft_reverse_rotate_stack(stack_b);
	ft_printf("rrb\n");
}

void	ft_reverse_rotate(t_stack **stack_a, t_stack **stack_b)
{
	if (!stack_a || !(*stack_a) || !(*stack_a)->next)
	{
		ft_reverse_rotate_b(stack_b);
		return ;
	}
	ft_reverse_rotate_stack(stack_a);
	ft_reverse_rotate_stack(stack_b);
	ft_printf("rrr\n");
}
