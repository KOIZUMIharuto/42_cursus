/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxx <xxxx@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 15:53:25 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/03/12 22:43:57 by xxxx             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include <stdio.h> // delete

typedef struct s_node
{
	int				num;
	int				index;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_ope
{
	char			*ope;
	struct s_ope	*next;
}	t_ope;

typedef struct s_ope_d
{
	char	*s;
	char	*p;
	char	*r;
	char	*rr;
} t_ope_d;

typedef struct s_all_ope_d
{
	t_ope_d	*a;
	t_ope_d	*b;
	t_ope_d	*ab;
} t_all_ope_d;

void		push_swap(t_node **stack_a, t_node **stack_b, int node_num);
t_node		*init_stack(void);
int			node_counter(t_node *stack);
int			ope_counter(t_ope *ope_list);
t_all_ope_d *init_ope_dict(void);
void		free_ope_dict(t_all_ope_d *ope_d);
int			add_ope_list(t_ope **ope_list, char *ope);
void		join_ope_list(t_ope **ope_list, t_ope *new_ope);
t_ope		*free_ope_list(t_ope *ope_list, t_ope *ope_list_tmp);
t_ope		*under_3_sort(t_node **stack, int num, t_ope_d *ope_d);
t_ope		*under_6_sort(
	t_node **stack_a, t_node **stack_b, int num, t_all_ope_d *ope_dict);
t_node		*duplicate_stack(t_node *stack);
t_ope		*sort__get_back(
	t_node **stack_a, t_node **stack_b, int num, t_all_ope_d *ope_dict);
void		free_stack(t_node *stack);
void		free_stack__exit(t_node *stack, t_node *stack_b, int status);
bool		join_node_and_list(t_node **prev_node, t_node *next_node);
void		check_dup__set_index(t_node *stack, t_node *new_node);
int			check_argv__create_stack(t_node **stack, int argc, char *argv[]);
int			check_str__create_stack(t_node **stack, char *str);
bool		is_all_sorted(t_node *stack_a, t_node *stack_b, int node_num);
bool		is_sorted(t_node *stack);
void		push(t_node **stack_from, t_node **stack_to);
void		swap(t_node **stack_, t_node **stack_b);
void		sub_swap_func(t_node **stack);
void		rotate(t_node **stack_a, t_node **stack_b);
void		reverse_rotate(t_node **stack_a, t_node **stack_b);

#endif
