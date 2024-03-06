/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 15:50:19 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/03/06 19:00:03 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	stack_printer(t_node *stack_a, t_node *stack_b, int node_num); // delete !
static void	printer(t_node *stack, char stack_name); // delete !

int	main(int argc, char *argv[])
{
	t_node	*stack_a;
	t_node	*stack_b;
	int		node_num;

	stack_a = NULL;
	if (argc == 1)
		return (0);
	else if (argc == 2)
	{
		if (argv[1][0] == '\0')
			return (0);
		node_num = check_str__create_stack(&stack_a, argv[1]);
	}
	else
		node_num = check_argv__create_stack(&stack_a, argc, argv);
	if (!stack_a)
		free_stack__exit (NULL, NULL, 1);
	stack_b = init_stack();
	if (!stack_b)
		free_stack__exit(stack_a, NULL, 1);
	if (!is_sorted(stack_a, stack_b, node_num))
		push_swap(&stack_a, &stack_b, node_num);
	stack_printer(stack_a, stack_b, node_num); // delete !
	// push(&stack_a, &stack_b);
	// stack_printer(stack_a, stack_b, node_num); // delete !
	// push(&stack_b, &stack_a);
	// stack_printer(stack_a, stack_b, node_num); // delete !
	// push(&stack_b, &stack_a);
	// stack_printer(stack_a, stack_b, node_num); // delete !
	free_stack__exit(stack_a, stack_b, 0);
	return (0);
}

static void	stack_printer(t_node *stack_a, t_node *stack_b, int node_num) // delete !
{
	printer(stack_a, 'a');
	printer(stack_b, 'b');
	printf("node_num : %d\n", node_num);
	printf("is_sorted : %d\n", is_sorted(stack_a, stack_b, node_num));
}

static void	printer(t_node *stack, char stack_name) // delete !
{
	int	loop_times = counter(stack);
	if (!stack)
		return (void)printf("stack_%c is NULL !\n\n", stack_name);
	printf("stack_%c\n", stack_name);
	for (int i = 0; i < loop_times + 1; i++)
	{
		printf("\t%d: %d[%d]\n", i, stack->num, stack->index);
		stack = stack->next;
	}
	printf("\n");
}

// __attribute__((destructor))  // delete !
// static void destructor() {
// 	system("leaks -q push_swap");
// }

// (sa && sb)    -> (ss)
// (ra && rb)    -> (rr)
// (rra && rrb)  -> (rrr)
// (sa && sa)    -> ()
// (sb && sb)    -> ()
// (ra && rra)   -> ()
// (rb && rrb)   -> ()
// (pa && pb)    -> ()
