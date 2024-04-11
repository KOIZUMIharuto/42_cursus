/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxx <xxxx@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 16:05:13 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/04/11 14:46:15 by xxxx             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static t_node	*init_stack(void);
static bool		check_str__create_stack(t_node **stack, char *str);
static bool		check_str_atoi(char **str, t_node *node);
static bool		check_dup__set_index(t_node *new_node);

void	create_stack(t_node **s_a, t_node **s_b, int argc, char *argv[])
{
	int		arg_index;

	*s_a = init_stack();
	if (!*s_a)
		free_stack__exit(NULL, NULL, 1);
	arg_index = 0;
	while (++arg_index < argc)
		if (!check_str__create_stack(s_a, argv[arg_index]))
			free_stack__exit(*s_a, NULL, 1);
	*s_a = (*s_a)->next;
	*s_b = init_stack();
	if (!*s_b)
		free_stack__exit(*s_a, NULL, 1);
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

static bool	check_str__create_stack(t_node **stack, char *str)
{
	t_node	*new_node;

	while (('\t' <= *str && *str <= '\r') || *str == ' ')
		str++;
	if (!*str)
		return (false);
	while (*str)
	{
		new_node = (t_node *)malloc (sizeof(t_node));
		if (!new_node)
			return (false);
		join_node_and_list(stack, new_node);
		if (!check_str_atoi(&str, new_node) || !check_dup__set_index(new_node))
			return (false);
	}
	return (true);
}

static bool	check_str_atoi(char **str, t_node *node)
{
	int	sign;

	sign = 1;
	if (**str == '-')
	{
		sign = -1;
		(*str)++;
	}
	if ((**str < '0' || '9' < **str))
		return (false);
	node->num = sign * (*((*str)++) - '0');
	while ('0' <= **str && **str <= '9')
	{
		if (node->num < INT_MIN / 10 || INT_MAX / 10 < node->num)
			return (false);
		node->num *= 10;
		if (node->num < INT_MIN + (**str - '0')
			|| INT_MAX - (**str - '0') < node->num)
			return (false);
		node->num += sign * (*((*str)++) - '0');
	}
	while (('\t' <= **str && **str <= '\r') || **str == ' ')
		(*str)++;
	return (true);
}

static bool	check_dup__set_index(t_node *new_node)
{
	t_node	*stack;

	new_node->index = 0;
	stack = new_node->next->next;
	while (stack->index != -1 && stack->next->index != -1)
	{
		if (stack->num == new_node->num)
			return (false);
		else if (stack->num > new_node->num)
			stack->index++;
		else if (stack->num < new_node->num)
			new_node->index++;
		stack = stack->next;
	}
	return (true);
}
