/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 15:50:19 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/03/14 18:37:35 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char *argv[])
{
	t_node	*s_a;
	t_node	*s_b;
	int		num;

	s_a = NULL;
	if (argc == 1)
		return (0);
	else if (argc == 2)
	{
		if (argv[1][0] == '\0')
			return (0);
		num = check_str__create_stack(&s_a, argv[1]);
	}
	else
		num = check_argv__create_stack(&s_a, argc, argv);
	if (!s_a)
		free_stack__exit (NULL, NULL, 1);
	s_b = init_stack();
	if (!s_b)
		free_stack__exit(s_a, NULL, 1);
	if (!is_all_sorted(s_a, s_b))
		push_swap(&s_a, &s_b, num);
	free_stack__exit(s_a, s_b, 0);
	return (0);
}

// __attribute__ ((destructor))

// static void	destructor(void)
// {
// 	system("leaks -q push_swap");
// }
