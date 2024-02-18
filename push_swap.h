/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madumerg <madumerg@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 12:08:34 by madumerg          #+#    #+#             */
/*   Updated: 2024/02/18 18:44:55 by madumerg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "Ft_Printf/ft_printf.h"
# include "Libft/libft.h"

# define ERROR "Error"

typedef struct s_stack
{
	int				content;
	struct s_stack	*next;
}	t_stack;

t_stack	*ft_stack_new(int value);
int		ft_stack_size(t_stack *stack);
t_stack	*ft_stack_last(t_stack *stack);
void	ft_stack_add_front(t_stack **stack, t_stack *new);
void	ft_stack_add_back(t_stack **stack, t_stack *new);
t_stack	*ft_stack_before_last(t_stack *stack);

void	ft_stack_push(t_stack **src, t_stack **dest);
void	ft_push_a(t_stack **stack_a, t_stack **stack_b);
void	ft_push_b(t_stack **stack_a, t_stack **stack_b);

void	ft_swap_stack(t_stack **stack);
void	ft_swap_a(t_stack **stack_a);
void	ft_swap_b(t_stack **stack_b);
void	ft_swap_swap(t_stack **stack_a, t_stack **stack_b);

void	ft_stack_rotate(t_stack **stack);
void	ft_rotate_a(t_stack **stack_a);
void	ft_rotate_b(t_stack **stack_b);
void	ft_rotate_rr(t_stack **stack_a, t_stack **stack_b);

void	ft_reverse_rotate_stack(t_stack **stack);
void	ft_reverse_rotate_a(t_stack **stack_a);
void	ft_reverse_rotate_b(t_stack **stack_b);
void	ft_reverse_rotate(t_stack **stack_a, t_stack **stack_b);

int		ft_mediane(t_stack **stack);
int		ft_is_mediane(t_stack **stack, int nb);
int		ft_quarter(t_stack **stack);
int		ft_is_quarter(t_stack **stack, int nb);

int		ft_find_max(t_stack **stack);
int		ft_find_min(t_stack **stack);

int		ft_nb_of_mov(int pos, int size);
void	ft_bis_best_m(int i_min_mov_b, int size_b, t_stack **stack_b);
int		ft_search_the_place(t_stack **stack_a, int nb);

void	ft_sort_stack(t_stack **stack, t_stack **stack_b);
void	ft_push_all(t_stack **stack_a, t_stack **stack_b);
void	ft_top_mov(t_stack **stack_a, t_stack **stack_b, int sz_a, int sz_b);
int		find_best_m(t_stack **stack_a, t_stack **stack_b, int sz_a, int sz_b);
int		ft_div_stack(t_stack **stack_a, t_stack **stack_b, int size_a);

void	ft_stack_delone(t_stack *stack);
void	ft_stack_clear(t_stack **stack);
void	ft_free_split(char **str);

int		ft_strlen_specific(char *str);
void	ft_check_overflow(int i, char **str, t_stack *stack);
void	ft_convert_white_space(char *str);
t_stack	*ft_parsing(int argc, char **argv);

void	ft_specific_mov_for_three_nb(t_stack **stack);
void	ft_sort_four(t_stack **stack, t_stack **stack_b);
void	ft_sort_five(t_stack **stack, t_stack **stack_b);
void	ft_specific_mov_for_five_nb(t_stack **stack, t_stack **stack_b);
void	ft_specific_mov(t_stack **stack, t_stack **stack_b);

int		ft_verif_double(t_stack **stack);
int		ft_is_sort(t_stack **stack);

int		ft_white_space(char *str);
int		ft_verif_right_char(char **argv);
int		ft_is_valid(char **argv);

#endif