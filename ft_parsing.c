/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madumerg <madumerg@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 09:32:08 by madumerg          #+#    #+#             */
/*   Updated: 2024/02/18 18:35:17 by madumerg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen_specific(char *str)
{
	int	i;
	int	cpt;

	i = 0;
	cpt = 0;
	while (str[i] == '0' || str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		cpt++;
		i++;
	}
	return (cpt);
}

void	ft_check_overflow(int i, char **str, t_stack *stack)
{
	if (ft_strlen_specific(str[i]) > 11)
	{
		ft_putendl_fd(ERROR, 2);
		ft_free_split(str);
		ft_stack_clear(&stack);
		exit (1);
	}
	if (ft_atoll(str[i]) > 2147483647 || ft_atoll(str[i]) < -2147483648)
	{
		ft_putendl_fd(ERROR, 2);
		ft_free_split(str);
		ft_stack_clear(&stack);
		exit (1);
	}
}

void	ft_convert_white_space(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 9 && str[i] <= 13)
			str[i] = 32;
		i++;
	}
}

t_stack	*ft_parsing(int argc, char **argv)
{
	int		i;
	int		j;
	t_stack	*stack;
	char	**tab;

	j = 1;
	stack = NULL;
	while (j < argc)
	{
		ft_convert_white_space(argv[j]);
		tab = ft_split(argv[j], ' ');
		i = 0;
		while (tab && tab[i])
		{
			ft_check_overflow(i, tab, stack);
			ft_stack_add_back(&stack, ft_stack_new(ft_atoi(tab[i])));
			i++;
		}
		ft_free_split(tab);
		j++;
	}
	return (stack);
}
