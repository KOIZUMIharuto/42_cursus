/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxx <xxxx@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 15:50:19 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/04/05 00:58:56 by xxxx             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char *argv[])
{
	t_node	*s_a;
	t_node	*s_b;

	s_a = NULL;
	s_b = NULL;
	if (argc == 1)
		return (0);
	else
		create_stack(&s_a, &s_b, argc, argv);
	if (!is_sorted(s_a))
		push_swap(&s_a, &s_b);
	stack_printer(s_a, s_b);
	free_stack__exit(s_a, s_b, 0);
	return (0);
}

void	stack_printer(t_node *s_a, t_node *s_b) // delete
{
	t_node	*s_tmp;

	ft_printf("stack a\n");
	s_tmp = s_a;
	for(int i = 0; i < node_counter(s_a) + 1; i++)
	{
		ft_printf ("%d : %d[%d]\n", i, s_tmp->num, s_tmp->index);
		s_tmp = s_tmp->next;
	}
	ft_printf("\nstack b\n");
	s_tmp = s_b;
	for(int i = 0; i < node_counter(s_b) + 1; i++)
	{
		ft_printf ("%d : %d[%d]\n", i, s_tmp->num, s_tmp->index);
		s_tmp = s_tmp->next;
	}
}

// __attribute__ ((destructor))

// static void	destructor(void)
// {
// 	system("leaks -q push_swap");
// }
