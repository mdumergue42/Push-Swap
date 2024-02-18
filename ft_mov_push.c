/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mov_push.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madumerg <madumerg@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 13:17:48 by madumerg          #+#    #+#             */
/*   Updated: 2024/02/18 14:58:06 by madumerg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stack_push(t_stack **src, t_stack **dest)
{
	t_stack	*temp;

	if (!src || !(*src))
		return ;
	temp = (*src)->next;
	(*src)->next = (*dest);
	(*dest) = (*src);
	(*src) = temp;
}

void	ft_push_a(t_stack **stack_a, t_stack **stack_b)
{
	if (!stack_b || !(*stack_b))
		return ;
	ft_stack_push(stack_b, stack_a);
	ft_printf("pa\n");
}

void	ft_push_b(t_stack **stack_a, t_stack **stack_b)
{
	if (!stack_a || !(*stack_a))
		return ;
	ft_stack_push(stack_a, stack_b);
	ft_printf("pb\n");
}
