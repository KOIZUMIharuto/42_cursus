/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 15:53:25 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/03/28 19:11:14 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include <stdio.h> // delete !

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

typedef struct s_ope_d
{
	char	*s;
	char	*p;
	char	*r;
	char	*rr;
}	t_ope_d;

typedef struct s_ope_ds
{
	t_ope_d	*a;
	t_ope_d	*b;
	t_ope_d	*ab;
}	t_ope_ds;

long		create_stack(t_node **s_a, t_node **s_b, int argc, char *argv[]);

void		push_swap(t_node **s_a, t_node **s_b, long num);
int			node_counter(t_node *stack);
void		free_stack(t_node *stack);
void		free_stack__exit(t_node *stack, t_node *s_b, int status);
bool		format_ope_list(t_ope **ope_l, t_ope_ds *ope_ds);
bool		join_node_and_list(t_node **prev_node, t_node *next_node);
bool		is_all_sorted(t_node *s_a, t_node *s_b);
bool		is_sorted(t_node *stack);
void		push(t_node **stack_from, t_node **stack_to);
void		swap(t_node **stack_, t_node **s_b);
void		sub_swap_func(t_node **stack);
void		rotate(t_node **s_a, t_node **s_b);
void		reverse_rotate(t_node **s_a, t_node **s_b);

void		stack_printer(t_node *s_a, t_node *s_b); // delete !

#endif
