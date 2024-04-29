/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 19:21:27 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/04/29 12:28:03 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static bool	print_ope_l(t_ope_l *ope_l);
static bool	free_ope_l(t_ope_l *ope_l, bool ret);

int	main(int argc, char *argv[])
{
	t_node	*s_a;
	t_node	*s_b;
	t_ope_l	*ope_l;
	int		exit_status;

	s_a = NULL;
	s_b = NULL;
	ope_l = NULL;
	exit_status = 0;
	if (argc == 1)
		return (0);
	else
		if (!create_stack(&s_a, &s_b, argc, argv))
			exit_status = 1;
	if (exit_status == 0 && !is_sorted(s_a))
		if (!insert_sort(&s_a, &s_b, &ope_l) || !print_ope_l(ope_l))
			exit_status = 1;
	free_ope_l(ope_l, false);
	free_stack_and_exit(s_a, s_b, exit_status);
	return (0);
}

static bool	print_ope_l(t_ope_l *ope_l)
{
	while (ope_l)
	{
		if (ft_printf("%s\n", ope_l->ope) == -1)
			return (false);
		ope_l = ope_l->next;
	}
	return (true);
}

static bool	free_ope_l(t_ope_l *ope_l, bool ret)
{
	t_ope_l	*tmp;

	while (ope_l)
	{
		tmp = ope_l->next;
		free(ope_l);
		ope_l = tmp;
	}
	return (ret);
}

// void	stack_printer(t_node *s_a, t_node *s_b) // for debug
// {
// 	t_node	*s_tmp;

// 	ft_printf("stack a\n");
// 	s_tmp = s_a;
// 	for(int i = 0; i < node_counter(s_a) + 1; i++)
// 	{
// 		ft_printf ("%d : %d[%d]\n", i, s_tmp->num, s_tmp->index);
// 		s_tmp = s_tmp->next;
// 	}
// 	ft_printf("stack b\n");
// 	s_tmp = s_b;
// 	for(int i = 0; i < node_counter(s_b) + 1; i++)
// 	{
// 		ft_printf ("%d : %d[%d]\n", i, s_tmp->num, s_tmp->index);
// 		s_tmp = s_tmp->next;
// 	}
// 	write(1, "\n", 1);
// }

// __attribute__((destructor))
// static void destructor() {
//     system("leaks -q push_swap");
// }
