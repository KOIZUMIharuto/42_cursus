/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stack__exit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxx <xxxx@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 11:09:51 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/03/12 21:33:46 by xxxx             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_stack__exit(t_node *stack_a, t_node *stack_b, int status)
{
	if (stack_a)
		free_stack(stack_a);
	if (stack_b)
		free_stack(stack_b);
	if (status > 0)
		printf("Error\n");
		// write (2, "Error\n", 6);
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
