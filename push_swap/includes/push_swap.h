/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 15:53:25 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/03/18 18:44:40 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>

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

void		push_swap(t_node **s_a, t_node **s_b, int num);
t_ope		*under_3(t_node **stack, t_ope_d *ope_d);
t_ope		*under_3_reverse(t_node **stack, t_ope_d *ope_d);
t_ope		*under_6(t_node **s_a, t_node **s_b, t_ope_ds *ope_ds);
t_ope		*over_6(t_node **s_a, t_node **s_b, t_ope_ds *ope_ds, t_ope *ope_l);
bool		format_ope_list(t_ope **ope_l, t_ope_ds *ope_ds);
bool		ope_set_checker(t_ope *ope_1, t_ope *ope_2, char *s_1, char *s_2);
bool		ft_strcmp(const char *s1, const char *s2);
t_node		*init_stack(void);
int			node_counter(t_node *stack);
int			ope_counter(t_ope *ope_l);
t_ope_ds	*init_ope_dict(void);
void		free_ope_dict(t_ope_ds *ope_ds);
int			add_ope_list(t_ope **ope_l, char *ope);
void		join_ope_list(t_ope **ope_l, t_ope *new_ope);
void		merge_ope_list(t_ope **ope_l, t_ope *new_ope_l);
t_ope		*free_ope_list(t_ope *ope_l, t_ope *ope_l_tmp);
t_ope		*free_s_ope(t_node *s_a, t_node *s_b, t_ope *ope_1, t_ope *ope_2);
int			find_min_index(t_node *stack);
int			find_min_num_index(t_node *stack);
int			find_max_num_index(t_node *stack);
bool		dup_stack(t_node *s_a, t_node *s_b, t_node **s_a_c, t_node **s_b_c);
t_ope		*sort__pa(t_node **s_a, t_node **s_b, t_ope_ds *ope_ds);
t_ope		*serch_small_by_r__pb(t_node **s_a, t_node **s_b, t_ope_d *ope_d);
t_ope		*serch_small_by_rr__pb(t_node **s_a, t_node **s_b, t_ope_d *ope_d);
t_ope		*push_large_half_to_a(t_node **s_a, t_node **s_b, t_ope_d *ope_d);
t_ope		*sort_pa_ra(t_node **s_a, t_node **s_b, t_ope_ds *ope_ds);
void		free_stack(t_node *stack);
void		free_stack__exit(t_node *stack, t_node *s_b, int status);
bool		join_node_and_list(t_node **prev_node, t_node *next_node);
void		check_dup__set_index(t_node *new_node);
int			check_argv__create_stack(t_node **stack, int argc, char *argv[]);
int			check_str__create_stack(t_node **stack, char *str);
bool		is_all_sorted(t_node *s_a, t_node *s_b);
bool		is_sorted(t_node *stack);
void		push(t_node **stack_from, t_node **stack_to);
void		swap(t_node **stack_, t_node **s_b);
void		sub_swap_func(t_node **stack);
void		rotate(t_node **s_a, t_node **s_b);
void		reverse_rotate(t_node **s_a, t_node **s_b);

#endif
