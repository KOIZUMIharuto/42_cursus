/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_half.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 09:01:41 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/03/18 18:44:32 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static t_ope	*pb_by_ra(t_node **s_a, t_node **s_b, t_ope_d *ope_d);
static t_ope	*pb_by_rra(t_node **s_a, t_node **s_b, t_ope_d *ope_d);

t_ope	*serch_small_by_r__pb(t_node **s_a, t_node **s_b, t_ope_d *ope_d)
{
	int		push_count;
	int		initial_num;
	t_ope	*ope_l;

	push_count = 0;
	initial_num = node_counter(*s_a);
	ope_l = NULL;
	while (push_count < initial_num / 2)
	{
		if ((*s_a)->index < initial_num / 2)
		{
			if (add_ope_list(&ope_l, ope_d->p))
				push(s_a, s_b);
			push_count++;
		}
		else
		{
			if (add_ope_list(&ope_l, ope_d->r))
				rotate(s_a, NULL);
		}
		if (is_all_sorted(*s_a, *s_b))
			break ;
	}
	return (ope_l);
}

t_ope	*serch_small_by_rr__pb(t_node **s_a, t_node **s_b, t_ope_d *ope_d)
{
	int		push_count;
	int		initial_num;
	t_ope	*ope_l;

	push_count = 0;
	initial_num = node_counter(*s_a);
	ope_l = NULL;
	while (push_count < initial_num / 2)
	{
		if ((*s_a)->index < initial_num / 2)
		{
			if (add_ope_list(&ope_l, ope_d->p))
				push(s_a, s_b);
			push_count++;
		}
		else
		{
			if (add_ope_list(&ope_l, ope_d->rr))
				reverse_rotate(s_a, NULL);
		}
		if (is_all_sorted(*s_a, *s_b))
			break ;
	}
	return (ope_l);
}

t_ope	*push_large_half_to_a(t_node **s_a, t_node **s_b, t_ope_d *ope_d)
{
	t_node	*s_a_copy;
	t_node	*s_b_copy;
	t_ope	*ope_l;
	t_ope	*ope_l_tmp;

	if (!dup_stack(*s_a, *s_b, &s_a_copy, &s_b_copy))
		return (NULL);
	ope_l = pb_by_ra(s_a, s_b, ope_d);
	ope_l_tmp = pb_by_rra(&s_a_copy, &s_b_copy, ope_d);
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
	return (ope_l);
}

static t_ope	*pb_by_ra(t_node **s_a, t_node **s_b, t_ope_d *ope_d)
{
	int		push_count;
	int		initial_num;
	int		initial_min_index;
	t_ope	*ope_l;

	push_count = 0;
	initial_num = node_counter(*s_b);
	initial_min_index = find_min_index(*s_b);
	ope_l = NULL;
	while (push_count < (initial_num + 1) / 2)
	{
		if ((*s_b)->index >= initial_num / 2 + initial_min_index)
		{
			if (add_ope_list(&ope_l, ope_d->p))
				push(s_b, s_a);
			push_count++;
		}
		else
		{
			if (add_ope_list(&ope_l, ope_d->r))
				rotate(s_b, NULL);
		}
	}
	return (ope_l);
}

static t_ope	*pb_by_rra(t_node **s_a, t_node **s_b, t_ope_d *ope_d)
{
	int		push_count;
	int		initial_num;
	int		initial_min_index;
	t_ope	*ope_l;

	push_count = 0;
	initial_num = node_counter(*s_b);
	initial_min_index = find_min_index(*s_b);
	ope_l = NULL;
	while (push_count < (initial_num + 1) / 2)
	{
		if ((*s_b)->index >= initial_num / 2 + initial_min_index)
		{
			if (add_ope_list(&ope_l, ope_d->p))
				push(s_b, s_a);
			push_count++;
		}
		else
		{
			if (add_ope_list(&ope_l, ope_d->rr))
				reverse_rotate(s_b, NULL);
		}
	}
	return (ope_l);
}
