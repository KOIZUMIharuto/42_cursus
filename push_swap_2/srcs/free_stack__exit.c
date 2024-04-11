/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stack__exit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxx <xxxx@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 11:09:51 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/04/04 12:41:39 by xxxx             ###   ########.fr       */
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
