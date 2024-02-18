/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madumerg <madumerg@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 12:06:08 by madumerg          #+#    #+#             */
/*   Updated: 2024/02/18 18:45:44 by madumerg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_div_stack(t_stack **stack_a, t_stack **stack_b, int size_a)
{
	int	val;
	int	size_base;
	int	quarter;

	val = ft_mediane(stack_a);
	size_a = ft_stack_size(*stack_a);
	quarter = ft_quarter(stack_a);
	size_base = size_a;
	while (size_a != (size_base / 2))
	{
		if ((*stack_a)->content > val)
			ft_rotate_a(stack_a);
		else
		{
			ft_push_b(stack_a, stack_b);
			if ((*stack_b)->content > quarter)
				ft_rotate_b(stack_b);
			size_a--;
		}
	}
	return (size_a);
}

int	find_best_m(t_stack **stack_a, t_stack **stack_b, int sz_a, int sz_b)
{
	int			nb_mov_a;
	int			cpt;
	int			i_min_mov_b;
	int			nb_mov_min_a;
	t_stack		*temp;

	cpt = 0;
	i_min_mov_b = 0;
	temp = (*stack_b);
	nb_mov_min_a = ft_search_the_place(stack_a, (*stack_b)->content);
	while (temp)
	{
		nb_mov_a = ft_search_the_place(stack_a, temp->content);
		if (ft_nb_of_mov(nb_mov_a, sz_a) + ft_nb_of_mov(cpt, sz_b) < \
		ft_nb_of_mov(nb_mov_min_a, sz_a) + ft_nb_of_mov(i_min_mov_b, sz_b))
		{
			nb_mov_min_a = nb_mov_a;
			i_min_mov_b = cpt;
		}
		cpt++;
		temp = temp->next;
	}
	ft_bis_best_m(i_min_mov_b, sz_b, stack_b);
	return (nb_mov_min_a);
}

void	ft_top_mov(t_stack **stack_a, t_stack **stack_b, int sz_a, int sz_b)
{
	int	pos;
	int	cpt;

	cpt = 0;
	pos = find_best_m(stack_a, stack_b, sz_a, sz_b);
	if (pos < (sz_a / 2))
	{
		while (stack_a && *stack_a && pos > cpt)
		{
			ft_rotate_a(stack_a);
			cpt++;
		}
	}
	else
	{
		cpt = sz_a;
		while (stack_a && *stack_a && pos < cpt)
		{
			ft_reverse_rotate_a(stack_a);
			cpt--;
		}
	}
}

void	ft_push_all(t_stack **stack_a, t_stack **stack_b)
{
	int	size_a;

	size_a = ft_stack_size(*stack_a);
	while (size_a > 2)
	{
		size_a = ft_div_stack(stack_a, stack_b, size_a);
	}
	while (stack_a && *stack_a != NULL)
	{
		ft_push_b(stack_a, stack_b);
	}
}

void	ft_sort_stack(t_stack **stack, t_stack **stack_b)
{
	int	size_b;
	int	size_a;

	ft_push_all(stack, stack_b);
	size_a = 0;
	size_b = ft_stack_size(*stack_b);
	while (size_b)
	{
		ft_top_mov(stack, stack_b, size_a, size_b);
		ft_push_a(stack, stack_b);
		size_b--;
		size_a++;
	}
	while (ft_is_sort(stack) == 0)
		ft_rotate_a(stack);
}
