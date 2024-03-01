/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argv_create_stack.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 16:05:13 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/03/01 19:07:29 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	check_argv_atoi(t_node *stack, const char *str, t_node *node);

int	check_argv_create_stack(t_node **stack, int argc, char *argv[])
{
	t_node	*new_node;
	int		node_count;

	*stack = NULL;
	new_node = NULL;
	node_count = -1;
	while (++node_count < argc - 1)
	{
		new_node = (t_node *)malloc (sizeof(t_node));
		if (!new_node)
			free_stack_exit(*stack, NULL, 1);
		new_node->next = NULL;
		join_list_and_node(stack, new_node);
		check_argv_atoi(*stack, argv[node_count + 1], new_node);
		check_dup_find_index(*stack, new_node);
	}
	join_list_and_node(&new_node, *stack);
	return (node_count);
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
		free_stack_exit (stack, NULL, 1);
	node->num = sign * (*(str++) - '0');
	while (node->num != 0 && '0' <= *str && *str <= '9')
	{
		if (node->num < INT_MIN / 10 || INT_MAX / 10 < node->num)
			free_stack_exit (stack, NULL, 1);
		node->num *= 10;
		if (node->num < INT_MIN + (*str - '0')
			|| INT_MAX - (*str - '0') < node->num)
			free_stack_exit (stack, NULL, 1);
		node->num += sign * (*(str++) - '0');
	}
	if (*str != '\0')
		free_stack_exit (stack, NULL, 1);
}
