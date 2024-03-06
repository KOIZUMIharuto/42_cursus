/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argv__create_stack.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 16:05:13 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/03/06 12:34:31 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	check_argv_atoi(t_node *stack, const char *str, t_node *node);

int	check_argv__create_stack(t_node **stack, int argc, char *argv[])
{
	t_node	*new_node;
	int		node_num;

	*stack = init_stack();
	if (!*stack)
		free_stack__exit(*stack, NULL, 1);
	node_num = -1;
	while (++node_num < argc - 1)
	{
		new_node = (t_node *)malloc (sizeof(t_node));
		if (!new_node)
			free_stack__exit(*stack, NULL, 1);
		join_node_and_list(stack, new_node);
		check_argv_atoi(*stack, argv[node_num + 1], new_node);
		check_dup__set_index(*stack, new_node);
	}
	*stack = (*stack)->next;
	return (node_num);
}

static void	check_argv_atoi(t_node *stack, const char *str, t_node *node)
{
	int	sign;

	sign = 1;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	if ((*str < '0' || '9' < *str) || (sign == -1 && *str == '0'))
		free_stack__exit (stack, NULL, 1);
	node->num = sign * (*(str++) - '0');
	while (node->num != 0 && '0' <= *str && *str <= '9')
	{
		if (node->num < INT_MIN / 10 || INT_MAX / 10 < node->num)
			free_stack__exit (stack, NULL, 1);
		node->num *= 10;
		if (node->num < INT_MIN + (*str - '0')
			|| INT_MAX - (*str - '0') < node->num)
			free_stack__exit (stack, NULL, 1);
		node->num += sign * (*(str++) - '0');
	}
	if (*str != '\0')
		free_stack__exit (stack, NULL, 1);
}
