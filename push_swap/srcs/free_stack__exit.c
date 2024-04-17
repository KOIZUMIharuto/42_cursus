/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stack__exit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:16:42 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/04/17 14:16:45 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_stack__exit(t_node *s_a, t_node *s_b, int status)
{
	if (s_a)
		free_stack(s_a);
	if (s_b)
		free_stack(s_b);
	if (status > 0)
		write (2, "Error\n", 6);
	if (status != -1)
		exit (status);
}

void	free_stack(t_node *stack)
{
	t_node	*stack_tmp;

	while (stack->index != -1)
	{
		stack_tmp = stack->next;
		free (stack);
		stack = stack_tmp;
	}
	free (stack);
}
