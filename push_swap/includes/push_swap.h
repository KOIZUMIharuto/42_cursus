/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 15:53:25 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/03/01 19:40:38 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h> // delete

typedef struct s_node
{
	int				num;
	int				index;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

void	free_stack_exit(t_node *stack, t_node *stack_b, int status);
void	join_list_and_node(t_node **prev_node, t_node *next_node);
void	check_dup_find_index(t_node *stack, t_node *new_node);
int		check_argv_create_stack(t_node **stack, int argc, char *argv[]);
int		check_str_create_stack(t_node **stack, char *str);
void	push(t_node **stack_from, t_node **stack_to);
void	swap(t_node **stack_, t_node **stack_b);
void	rotate(t_node **stack_a, t_node **stack_b);
void	reverse_rotate(t_node **stack_a, t_node **stack_b);

#endif
