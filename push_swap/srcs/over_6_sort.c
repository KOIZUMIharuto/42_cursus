/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   over_6_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 14:57:10 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/03/14 19:51:14 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static bool		is_sort_by_rra(t_ope **ope_l, t_node **s_a, t_ope_d *ope_d);
static t_ope	*recursive_s(t_node **s_a, t_node **s_b, t_ope_ds *ope_ds);
static int		push_ope_counter(t_ope *ope_l);

static t_ope	*start_recursive_s(
	t_ope *ope_l, t_node **s_a, t_node **s_b, t_ope_ds *ope_ds)
{
	t_ope	*ope_l_tmp;

	ope_l_tmp = recursive_s(s_a, s_b, ope_ds);
	join_ope_list(&ope_l, ope_l_tmp);
	while ((*s_a)->index != 0)
		if (add_ope_list(&ope_l, ope_ds->a->p))
			push(s_a, s_b);
	ope_l_tmp = recursive_s(s_a, s_b, ope_ds);
	join_ope_list(&ope_l, ope_l_tmp);
	return (ope_l);
}

t_ope	*over_6(
	t_node **s_a, t_node **s_b, t_ope_ds *ope_ds, t_ope *ope_l)
{
	t_node	*s_a_copy;
	t_node	*s_b_copy;
	t_ope	*ope_l_tmp;

	if (is_sort_by_rra(&ope_l, s_a, ope_ds->a))
		return (ope_l);
	if (!dup_stack(*s_a, *s_b, &s_a_copy, &s_b_copy))
		return (NULL);
	ope_l = serch_small_by_r__pb(s_a, s_b, ope_ds->a);
	ope_l_tmp = serch_small_by_rr__pb(&s_a_copy, &s_b_copy, ope_ds->a);
	if (!ope_l || !ope_l_tmp)
		return (free_s_ope(s_a_copy, s_b_copy, ope_l, ope_l_tmp));
	if (ope_counter(ope_l) > ope_counter(ope_l_tmp))
	{
		(void)free_s_ope(*s_a, *s_b, ope_l, NULL);
		*s_a = s_a_copy;
		*s_b = s_b_copy;
		ope_l = ope_l_tmp;
	}
	else
		(void)free_s_ope(s_a_copy, s_b_copy, ope_l_tmp, NULL);
	if (is_all_sorted(*s_a, *s_b))
		return (ope_l);
	return (start_recursive_s(ope_l, s_a, s_b, ope_ds));
}

static bool	is_sort_by_rra(t_ope **ope_l, t_node **s_a, t_ope_d *ope_d)
{
	int	num;
	int	rr_count;

	num = node_counter(*s_a);
	rr_count = 0;
	while (rr_count++ < num / 2)
	{
		if (add_ope_list(ope_l, ope_d->rr))
			reverse_rotate(s_a, NULL);
		if (is_sorted(*s_a))
			return (true);
	}
	(void)free_ope_list(*ope_l, NULL);
	while (rr_count++ <= num)
		reverse_rotate(s_a, NULL);
	return (false);
}

static t_ope	*recursive_s(t_node **s_a, t_node **s_b, t_ope_ds *ope_ds)
{
	t_ope	*ope_l;
	t_ope	*ope_l_tmp;
	int		push_count;

	if (node_counter(*s_b) <= 3)
		return (sort_pa_ra(s_a, s_b, ope_ds));
	ope_l = push_large_half_to_a(s_a, s_b, ope_ds->b);
	push_count = push_ope_counter(ope_l);
	ope_l_tmp = recursive_s(s_a, s_b, ope_ds);
	join_ope_list(&ope_l, ope_l_tmp);
	while (push_count-- > 0)
		if (add_ope_list(&ope_l, ope_ds->a->p))
			push(s_a, s_b);
	ope_l_tmp = recursive_s(s_a, s_b, ope_ds);
	join_ope_list(&ope_l, ope_l_tmp);
	return (ope_l);
}

static int	push_ope_counter(t_ope *ope_l)
{
	int		push_count;

	if (!ope_l)
		return (-1);
	push_count = 0;
	while (ope_l)
	{
		if (ft_strcmp(ope_l->ope, "pa"))
			push_count++;
		ope_l = ope_l->next;
	}
	return (push_count);
}
