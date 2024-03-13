/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxx <xxxx@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 15:50:19 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/03/13 15:03:37 by xxxx             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
	if (!is_all_sorted(stack_a, stack_b, node_num))
		push_swap(&stack_a, &stack_b, node_num);
	free_stack__exit(stack_a, stack_b, 0);
	return (0);
}

// __attribute__((destructor))  // delete !
// static void destructor() {
// 	system("leaks -q push_swap");
// }
