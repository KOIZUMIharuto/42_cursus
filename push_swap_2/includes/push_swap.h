/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 15:53:25 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/03/31 12:56:01 by hkoizumi         ###   ########.fr       */
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
}	t_node;

typedef struct s_ope
{
	char			*ope;
	struct s_ope	*prev;
	struct s_ope	*next;
}	t_ope;

long		create_stack(t_node **s_a, t_node **s_b, int argc, char *argv[]);

void		push_swap(t_node **s_a, t_node **s_b, long num);
int			node_counter(t_node *stack);

void		free_stack(t_node *stack);
void		free_stack__exit(t_node *stack, t_node *s_b, int status);

bool		add_ope_list(t_ope **ope_l, char *ope);
bool		format_ope_list(t_ope **ope_l);

bool		join_node_and_list(t_node **prev_node, t_node *next_node);
long		get_min_max_index(t_node *stack, int sign);

bool		is_all_sorted(t_node *s_a, t_node *s_b);
bool		is_sorted(t_node *stack);

void		swap_util_func(t_node **stack);
bool		push(t_node **s_from, t_node **s_to, t_ope **ope_l, char *ope);
bool		swap(t_node **stack_, t_node **s_b, t_ope **ope_l, char *ope);
bool		rotate(t_node **s_a, t_node **s_b, t_ope **ope_l, char *ope);
bool		r_rotate(t_node **s_a, t_node **s_b, t_ope **ope_l, char *ope);

void		stack_printer(t_node *s_a, t_node *s_b); // delete !

#endif
