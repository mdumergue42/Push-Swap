/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_ft.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madumerg <madumerg@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 13:33:05 by madumerg          #+#    #+#             */
/*   Updated: 2024/02/18 14:57:43 by madumerg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_stack_new(int value)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->content = value;
	new->next = NULL;
	return (new);
}

int	ft_stack_size(t_stack *stack)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	if (!stack)
		return (0);
	tmp = stack;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

t_stack	*ft_stack_last(t_stack *stack)
{
	t_stack	*temp;

	temp = stack;
	if (!stack)
		return (NULL);
	while (temp->next)
		temp = temp->next;
	return (temp);
}

void	ft_stack_add_front(t_stack **stack, t_stack *new)
{
	if (!new || !stack)
		return ;
	if (*stack)
		new->next = *stack;
	*stack = new;
	return ;
}

void	ft_stack_add_back(t_stack **stack, t_stack *new)
{
	if (!new || !stack)
		return ;
	if (!(*stack))
	{
		*stack = new;
		return ;
	}
	ft_stack_last(*stack)->next = new;
	return ;
}
