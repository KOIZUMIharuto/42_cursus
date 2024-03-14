/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_str__create_stack.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 16:05:13 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/03/14 14:04:27 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	check_str_atoi(char **str, t_node *node);

int	check_str__create_stack(t_node **stack, char *str)
{
	t_node	*new_node;
	int		num;

	*stack = init_stack();
	if (!*stack)
		free_stack__exit(*stack, NULL, 1);
	num = 0;
	while (*str)
	{
		new_node = (t_node *)malloc (sizeof(t_node));
		if (!new_node)
			free_stack__exit(*stack, NULL, 1);
		if (!join_node_and_list(stack, new_node))
			free_stack__exit(*stack, new_node, 1);
		check_str_atoi(&str, new_node);
		check_dup__set_index(new_node);
		num++;
	}
	*stack = (*stack)->next;
	return (num);
}

static void	check_str_atoi(char **str, t_node *node)
{
	int	sign;

	sign = 1;
	if (**str == '-')
	{
		sign = -1;
		(*str)++;
	}
	if ((**str < '0' || '9' < **str) || (sign == -1 && **str == '0'))
		free_stack__exit (node, NULL, 1);
	node->num = sign * (*((*str)++) - '0');
	while (node->num != 0 && '0' <= **str && **str <= '9')
	{
		if (node->num < INT_MIN / 10 || INT_MAX / 10 < node->num)
			free_stack__exit (node, NULL, 1);
		node->num *= 10;
		if (node->num < INT_MIN + (**str - '0')
			|| INT_MAX - (**str - '0') < node->num)
			free_stack__exit (node, NULL, 1);
		node->num += sign * (*((*str)++) - '0');
	}
	if (**str != '\0' && (**str != ' ' || *(*str + 1) == '\0'))
		free_stack__exit (node, NULL, 1);
	if (**str == ' ')
		(*str)++;
}
