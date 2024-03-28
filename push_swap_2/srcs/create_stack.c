/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 16:05:13 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/03/28 19:11:01 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static t_node	*init_stack(void);
static long		check_str__create_stack(t_node **stack, char *str);
static void		check_str_atoi(char **str, t_node *node);
static void		check_dup__set_index(t_node *new_node);

long	create_stack(t_node **s_a, t_node **s_b, int argc, char *argv[])
{
	int		arg_index;
	long	node_count;
	long	node_count_tmp;

	*s_a = init_stack();
	if (!*s_a)
		free_stack__exit(*s_a, NULL, 1);
	arg_index = 0;
	node_count = 0;
	while (++arg_index < argc)
	{
		node_count_tmp = check_str__create_stack(s_a, argv[arg_index]);
		if (node_count_tmp == 0)
			free_stack__exit(*s_a, NULL, 1);
		node_count += node_count_tmp;
	}
	*s_a = (*s_a)->next;
	*s_b = init_stack();
	if (!*s_b)
		free_stack__exit(*s_a, NULL, 1);
	return (node_count);
}

static t_node	*init_stack(void)
{
	t_node	*stack;

	stack = (t_node *)malloc (sizeof(t_node));
	if (!stack)
		return (NULL);
	stack->next = stack;
	stack->prev = stack;
	stack->num = 42;
	stack->index = -1;
	return (stack);
}

static long	check_str__create_stack(t_node **stack, char *str)
{
	t_node	*new_node;
	long	node_count;

	node_count = 0;
	while (('\t' <= *str && *str <= '\r') || *str == ' ')
		str++;
	while (*str)
	{
		new_node = (t_node *)malloc (sizeof(t_node));
		if (!new_node)
			free_stack__exit(*stack, NULL, 1);
		if (!join_node_and_list(stack, new_node))
			free_stack__exit(*stack, new_node, 1);
		check_str_atoi(&str, new_node);
		check_dup__set_index(new_node);
		node_count++;
	}
	return (node_count);
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
	if ((**str < '0' || '9' < **str))
		free_stack__exit (node, NULL, 1);
	node->num = sign * (*((*str)++) - '0');
	while ('0' <= **str && **str <= '9')
	{
		if (node->num < INT_MIN / 10 || INT_MAX / 10 < node->num)
			free_stack__exit (node, NULL, 1);
		node->num *= 10;
		if (node->num < INT_MIN + (**str - '0')
			|| INT_MAX - (**str - '0') < node->num)
			free_stack__exit (node, NULL, 1);
		node->num += sign * (*((*str)++) - '0');
	}
	while (('\t' <= **str && **str <= '\r') || **str == ' ')
		(*str)++;
}

static void	check_dup__set_index(t_node *new_node)
{
	t_node	*stack;

	new_node->index = 0;
	stack = new_node->next->next;
	while (stack->index != -1 && stack->next->index != -1)
	{
		if (stack->num == new_node->num)
			free_stack__exit(new_node, NULL, 1);
		else if (stack->num > new_node->num)
			stack->index++;
		else if (stack->num < new_node->num)
			new_node->index++;
		stack = stack->next;
	}
}
