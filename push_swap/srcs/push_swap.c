/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 19:21:27 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/04/17 14:17:13 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static bool	print_ope_l(t_ope_l *ope_l);
static bool free_ope_l(t_ope_l *ope_l, bool ret);

int	main(int argc, char *argv[])
{
	t_node	*s_a;
	t_node	*s_b;
	t_ope_l	*ope_l;

	s_a = NULL;
	s_b = NULL;
	ope_l = NULL;
	if (argc == 1)
		return (0);
	else
		create_stack(&s_a, &s_b, argc, argv);
	if (!is_sorted(s_a))
	{
		if (!insert_sort(&s_a, &s_b, &ope_l))
			return (free_ope_l(ope_l, false));
		if (!print_ope_l(ope_l))
			return (free_ope_l(ope_l, false));
	}
	free_stack__exit(s_a, s_b, 0);
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

static bool free_ope_l(t_ope_l *ope_l, bool ret)
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