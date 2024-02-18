/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madumerg <madumerg@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 09:32:32 by madumerg          #+#    #+#             */
/*   Updated: 2024/02/18 18:23:42 by madumerg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_white_space(char *str)
{
	int	i;
	int	cpt;

	i = 0;
	cpt = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
			cpt++;
		i++;
	}
	return (cpt);
}

int	ft_verif_right_char(char **argv)
{
	int	i;
	int	j;

	j = 1;
	while (argv[j])
	{
		i = 0;
		if (ft_white_space(argv[j]) == 0)
		{
			ft_putendl_fd(ERROR, 2);
			exit (1);
		}
		while (argv[j][i])
		{
			if (!((ft_isdigit(argv[j][i]) == 1) || argv[j][i] == '-' || \
			argv[j][i] == '+' || ft_is_space(argv[j][i])))
			{
				ft_putendl_fd(ERROR, 2);
				exit (1);
			}
			i++;
		}
		j++;
	}
	return (0);
}

int	ft_is_valid(char **argv)
{
	int	i;
	int	j;

	j = 1;
	while (argv[j])
	{
		i = 0;
		while (argv[j][i])
		{
			if (argv[j][i] == '+' || argv[j][i] == '-')
			{
				if ((i != 0 && ((ft_is_space(argv[j][i - 1]) == 0))) || \
				(ft_isdigit(argv[j][i + 1]) == 0))
				{
					ft_putendl_fd(ERROR, 2);
					exit (1);
				}
			}
			i++;
		}
		j++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	*stack;
	t_stack	*stack_b;

	stack_b = NULL;
	if (argc < 2)
		return (0);
	ft_verif_right_char(argv);
	ft_is_valid(argv);
	stack = ft_parsing(argc, argv);
	if (ft_verif_double(&stack) == -1)
	{
		ft_putendl_fd(ERROR, 2);
		ft_stack_clear(&stack);
		exit (1);
	}
	if (ft_is_sort(&stack))
	{
		ft_stack_clear(&stack);
		return (0);
	}
	ft_specific_mov(&stack, &stack_b);
	ft_sort_stack(&stack, &stack_b);
	ft_stack_clear(&stack);
	return (0);
}
