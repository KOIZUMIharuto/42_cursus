/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:17:41 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/05/17 12:55:53 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"

typedef struct s_node
{
	int				num;
	long			index;
	struct s_node	*prev;
	struct s_node	*next;
}		t_node;

typedef struct s_ope_list
{
	char				*ope;
	struct s_ope_list	*prev;
	struct s_ope_list	*next;
}		t_ope_l;

typedef struct s_ope_count
{
	long	ra;
	long	rb;
	long	rr;
	long	rra;
	long	rrb;
	long	rrr;
}		t_ope_c;

bool	create_stack(t_node **s_a, t_node **s_b, int argc, char *argv[]);
void	join_node_and_list(t_node **prev_node, t_node *next_node);

long	node_counter(t_node *stack);

bool	add_new_ope(t_ope_l **ope_l, char *ope);

void	free_stack_and_exit(t_node *stack, t_node *s_b, int status);

long	get_max_index(t_node *stack);
long	get_min_index(t_node *stack);
long	get_pos(t_node *stack, long index);

bool	is_sorted(t_node *stack);
bool	is_almost_sorted(t_node *stack);

bool	insert_sort(t_node **s_a, t_node **s_b, t_ope_l **ope_l);

void	swap_util_func(t_node **stack);

bool	push(t_node **s_from, t_node **s_to, t_ope_l **ope_l, char *ope);
bool	swap(t_node **s_a, t_node **s_b, t_ope_l **ope_l, char *ope);
bool	rotate(t_node **s_a, t_node **s_b, t_ope_l **ope_l, char *ope);
bool	r_rotate(t_node **s_a, t_node **s_b, t_ope_l **ope_l, char *ope);

// void	stack_printer(t_node *s_a, t_node *s_b); // for debug

#endif
