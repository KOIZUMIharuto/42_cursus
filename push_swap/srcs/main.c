/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 15:50:19 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/03/01 20:47:58 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	stack_printer(t_node *stack_a, t_node *stack_b); // delete !
static void	printer(t_node *stack, char stack_name); // delete !

int	main(int argc, char *argv[])
{
	t_node	*stack_a;
	t_node	*stack_b;
	int		node_count;

	stack_a = NULL;
	if (argc == 1)
		return (0);
	else if (argc == 2)
		node_count = check_str_create_stack(&stack_a, argv[1]);
	else
		node_count = check_argv_create_stack(&stack_a, argc, argv);
	if (!stack_a)
		free_stack_exit (NULL, NULL, 1);
	stack_b = NULL;
	stack_printer(stack_a, stack_b); // delete !
	free_stack_exit(stack_a, stack_b, 0);
	return (0);
}

static void	stack_printer(t_node *stack_a, t_node *stack_b) // delete !
{
	printer(stack_a, 'a');
	printer(stack_b, 'b');
}

static void	printer(t_node *stack, char stack_name) // delete !
{
	if (!stack)
		return (void)printf("stack_%c\n\tempty!\n\n", stack_name);
	printf("stack_%c\n", stack_name);
	for (int i = 0; i < 10; i++)
	{
		printf("\t%d: %d[%d]\n", i, stack->num, stack->index);
		stack = stack->next;
		if (!stack)
			break ;
	}
	printf("\n");
}

__attribute__((destructor))  // delete !
static void destructor() {
	system("leaks -q push_swap");
}
