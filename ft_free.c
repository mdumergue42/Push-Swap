/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madumerg <madumerg@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 19:00:29 by madumerg          #+#    #+#             */
/*   Updated: 2024/02/14 10:38:40 by madumerg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stack_delone(t_stack *stack)
{
	if (!stack)
		return ;
	free (stack);
}

void	ft_stack_clear(t_stack **stack)
{
	t_stack	*temp;

	if (!stack || !(*stack))
		return ;
	temp = NULL;
	while (*stack)
	{
		temp = (*stack)->next;
		ft_stack_delone(*stack);
		(*stack) = temp;
	}
	free(*stack);
}

void	ft_free_split(char **str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}
