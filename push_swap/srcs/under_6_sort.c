/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   under_6_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:59:02 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/03/18 12:58:33 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static t_ope	*pb_search_by_ra(
	t_node **s_a, t_node **s_b, int num, t_ope_d *ope_d)
{
	t_ope	*ope_l;
	int		move_count;

	ope_l = NULL;
	move_count = 0;
	while (move_count < num - 3)
	{
		if ((*s_a)->index < num - 3)
		{
			if (!add_ope_list(&ope_l, ope_d->p))
				return (NULL);
			push(s_a, s_b);
			move_count++;
		}
		else
		{
			if (!add_ope_list(&ope_l, ope_d->r))
				return (NULL);
			rotate(s_a, NULL);
		}
	}
	return (ope_l);
}

static t_ope	*pb_search_by_rra(
	t_node **s_a, t_node **s_b, int num, t_ope_d *ope_d)
{
	t_ope	*ope_l;
	int		move_count;

	ope_l = NULL;
	move_count = 0;
	while (move_count < num - 3)
	{
		if ((*s_a)->index < num - 3)
		{
			if (!add_ope_list(&ope_l, ope_d->p))
				return (NULL);
			push(s_a, s_b);
			move_count++;
		}
		else
		{
			if (!add_ope_list(&ope_l, ope_d->rr))
				return (NULL);
			reverse_rotate(s_a, NULL);
		}
	}
	return (ope_l);
}

static t_ope	*sort_for_compare(t_node **s_a, t_node **s_b, t_ope_ds *ope_ds)
{
	static bool	is_first = true;
	t_ope		*ope_l;
	t_ope		*ope_l_tmp;
	int			num;

	num = node_counter(*s_a);
	if (is_first)
		ope_l = pb_search_by_ra(s_a, s_b, num, ope_ds->a);
	else
		ope_l = pb_search_by_rra(s_a, s_b, num, ope_ds->a);
	if (!ope_l)
		return (NULL);
	ope_l_tmp = sort__pa(s_a, s_b, ope_ds);
	if (!ope_l_tmp)
		return (free_ope_list(ope_l, NULL));
	join_ope_list(&ope_l, ope_l_tmp);
	is_first = !is_first;
	return (ope_l);
}

t_ope	*under_6(
	t_node **s_a, t_node **s_b, t_ope_ds *ope_ds)
{
	t_node	*s_a_copy;
	t_node	*s_b_copy;
	t_ope	*ope_l_1;
	t_ope	*ope_l_2;

	if (!dup_stack(*s_a, *s_b, &s_a_copy, &s_b_copy))
		return (NULL);
	ope_l_1 = sort_for_compare(s_a, s_b, ope_ds);
	ope_l_2 = sort_for_compare(&s_a_copy, &s_b_copy, ope_ds);
	if (!ope_l_1 || !ope_l_2)
	{
		free_stack__exit(s_a_copy, s_b_copy, -1);
		return (free_ope_list(ope_l_1, ope_l_2));
	}
	if (ope_counter(ope_l_1) > ope_counter(ope_l_2))
	{
		(void)free_s_ope(*s_a, *s_b, ope_l_1, NULL);
		*s_a = s_a_copy;
		*s_b = s_b_copy;
		return (ope_l_2);
	}
	(void)free_s_ope(s_a_copy, s_b_copy, NULL, ope_l_2);
	return (ope_l_1);
}
