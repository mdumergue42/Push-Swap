/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mov_swap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madumerg <madumerg@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 10:00:53 by madumerg          #+#    #+#             */
/*   Updated: 2024/02/18 14:58:22 by madumerg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_stack(t_stack **stack)
{
	int	temp;

	if (!stack || !(*stack))
		return ;
	temp = (*stack)->content;
	(*stack)->content = (*stack)->next->content;
	(*stack)->next->content = temp;
}

void	ft_swap_a(t_stack **stack_a)
{
	ft_swap_stack(stack_a);
	ft_printf("sa\n");
}

void	ft_swap_b(t_stack **stack_b)
{
	ft_swap_stack(stack_b);
	ft_printf("sb\n");
}

void	ft_swap_swap(t_stack **stack_a, t_stack **stack_b)
{
	ft_swap_stack(stack_a);
	ft_swap_stack(stack_b);
	ft_printf("ss\n");
}
