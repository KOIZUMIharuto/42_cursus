/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 12:22:39 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/03/06 12:32:29 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	counter(t_node *stack)
{
	int	counter;

	if (!stack)
		return (-1);
	counter = 0;
	while (stack->index != -1)
	{
		counter++;
		stack = stack->next;
	}
	return (counter);
}
