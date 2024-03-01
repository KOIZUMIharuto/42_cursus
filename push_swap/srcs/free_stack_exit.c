/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stack_exit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 15:48:35 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/03/01 19:22:28 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	free_stack(t_node *stack);

void	free_stack_exit(t_node *stack_a, t_node *stack_b, int status)
{
	free_stack(stack_a);
	free_stack(stack_b);
	if (status != 0)
		write (2, "Error\n", 6);
	exit (status);
}

static void	free_stack(t_node *stack)
{
	t_node	*stack_tmp;

	if (stack && stack->prev)
		stack->prev->next = NULL;
	while (stack)
	{
		stack_tmp = stack->next;
		free (stack);
		stack = stack_tmp;
	}
}
