/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxx <xxxx@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 17:26:37 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/04/05 07:16:46 by xxxx             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	pop(t_node **stack);

bool	push(t_node **s_from, t_node **s_to, t_ope_l **ope_l, char *ope)
{
	t_node	*node_tmp;

	if (!s_from || !*s_from || !add_new_ope(ope_l, ope))
		return (false);
	if ((*s_from)->index != -1)
	{
		node_tmp = *s_from;
		pop(s_from);
		(*s_to)->prev->next = node_tmp;
		node_tmp->prev = (*s_to)->prev;
		(*s_to)->prev = node_tmp;
		node_tmp->next = *s_to;
		*s_to = node_tmp;
	}
	return (true);
}

static void	pop(t_node **stack)
{
	(*stack)->prev->next = (*stack)->next;
	(*stack)->next->prev = (*stack)->prev;
	*stack = (*stack)->next;
}
