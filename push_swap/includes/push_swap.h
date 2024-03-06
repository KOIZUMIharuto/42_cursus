/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 15:53:25 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/03/06 17:03:31 by hkoizumi         ###   ########.fr       */
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

void	push_swap(t_node **stack_a, t_node **stack_b, int node_num);
t_node	*init_stack(void);
int		counter(t_node *stack);
void	do_ope(t_node **stack_a, t_node **stack_b, char *operation);
t_ope	*under_six_sort(t_node **stack_a, t_node **stack_b, int node_num);
void	free_stack__exit(t_node *stack, t_node *stack_b, int status);
void	join_node_and_list(t_node **prev_node, t_node *next_node);
void	check_dup__set_index(t_node *stack, t_node *new_node);
int		check_argv__create_stack(t_node **stack, int argc, char *argv[]);
int		check_str__create_stack(t_node **stack, char *str);
bool	is_sorted(t_node *stack_a, t_node *stack_b, int node_num);
void	push(t_node **stack_from, t_node **stack_to);
void	swap(t_node **stack_, t_node **stack_b);
void	rotate(t_node **stack_a, t_node **stack_b);
void	reverse_rotate(t_node **stack_a, t_node **stack_b);

#endif
