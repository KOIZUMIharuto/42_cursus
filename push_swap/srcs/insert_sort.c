/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:16:52 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/04/25 16:24:13 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static bool		insert_sort_util(t_node **s_a, t_node **s_b, t_ope_l **ope_l);
static t_ope_c	count_ra_rra(t_node *s_a, t_node *s_b, long rb_c, long index);
static long		compress_and_sum(t_ope_c *ope_c);
static bool		do_ope(t_ope_c o_c, t_node **s_a, t_node **s_b, t_ope_l **o_l);

bool	insert_sort(t_node **s_a, t_node **s_b, t_ope_l **ope_l)
{
	long	min_i;

	while (node_counter(*s_a) > 3 && !is_almost_sorted(*s_a))
		if (!push(s_a, s_b, ope_l, "pb"))
			return (false);
	if (!is_almost_sorted(*s_a))
		if (!swap(s_a, s_b, ope_l, "sa"))
			return (false);
	while (node_counter(*s_b))
		if (!insert_sort_util(s_a, s_b, ope_l))
			return (false);
	min_i = get_min_index(*s_a);
	if (get_pos(*s_a, min_i) < node_counter(*s_a) - get_pos(*s_a, min_i))
	{
		while (get_pos(*s_a, min_i) != 0)
			if (!rotate(s_a, s_b, ope_l, "ra"))
				return (false);
	}
	else
	{
		while (get_pos(*s_a, min_i) != 0)
			if (!r_rotate(s_a, s_b, ope_l, "rra"))
				return (false);
	}
	return (true);
}

static bool	insert_sort_util(t_node **s_a, t_node **s_b, t_ope_l **ope_l)
{
	t_node	*s_b_tmp;
	t_ope_c	least_ope_count;
	t_ope_c	ope_count;
	long	rb_count;

	s_b_tmp = *s_b;
	rb_count = 0;
	least_ope_count = count_ra_rra(*s_a, *s_b, rb_count, s_b_tmp->index);
	while (s_b_tmp->next->index != -1)
	{
		rb_count++;
		s_b_tmp = s_b_tmp->next;
		ope_count = count_ra_rra(*s_a, *s_b, rb_count, s_b_tmp->index);
		if (compress_and_sum(&ope_count) < compress_and_sum(&least_ope_count))
			least_ope_count = ope_count;
	}
	if (!do_ope(least_ope_count, s_a, s_b, ope_l))
		return (false);
	if (!push(s_b, s_a, ope_l, "pa"))
		return (false);
	return (true);
}

static t_ope_c	count_ra_rra(t_node *s_a, t_node *s_b, long rb_c, long index)
{
	t_node	*s_a_tmp;
	t_ope_c	ope_count;
	long	ra_count;

	if (rb_c < node_counter(s_b) - rb_c)
		ope_count = (t_ope_c){0, rb_c, 0, 0, 0, 0};
	else
		ope_count = (t_ope_c){0, 0, 0, 0, node_counter(s_b) - rb_c, 0};
	ra_count = 0;
	s_a_tmp = s_a;
	if ((index < s_a_tmp->index && index < s_a_tmp->prev->prev->index)
		|| index < get_min_index(s_a) || get_max_index(s_a) < index)
		while (s_a_tmp->index != get_min_index(s_a) && ra_count++ > -1)
			s_a_tmp = s_a_tmp->next;
	if (get_min_index(s_a) < index && index < get_max_index(s_a))
		while (s_a_tmp->index < index
			&& s_a_tmp->next->index != -1 && ra_count++ > -1)
			s_a_tmp = s_a_tmp->next;
	if (ra_count < node_counter(s_a) - ra_count)
		ope_count.ra = ra_count;
	else
		ope_count.rra = node_counter(s_a) - ra_count;
	return (ope_count);
}

static long	compress_and_sum(t_ope_c *ope_c)
{
	long	sum;

	while (ope_c->ra > 0 && ope_c->rb > 0)
	{
		ope_c->ra--;
		ope_c->rb--;
		ope_c->rr++;
	}
	while (ope_c->rra > 0 && ope_c->rrb > 0)
	{
		ope_c->rra--;
		ope_c->rrb--;
		ope_c->rrr++;
	}
	sum = ope_c->ra + ope_c->rb + ope_c->rr
		+ ope_c->rra + ope_c->rrb + ope_c->rrr;
	return (sum);
}

static bool	do_ope(t_ope_c o_c, t_node **s_a, t_node **s_b, t_ope_l **o_l)
{
	while (o_c.ra--)
		if (!rotate(s_a, s_b, o_l, "ra"))
			return (false);
	while (o_c.rb--)
		if (!rotate(s_a, s_b, o_l, "rb"))
			return (false);
	while (o_c.rr--)
		if (!rotate(s_a, s_b, o_l, "rr"))
			return (false);
	while (o_c.rra--)
		if (!r_rotate(s_a, s_b, o_l, "rra"))
			return (false);
	while (o_c.rrb--)
		if (!r_rotate(s_a, s_b, o_l, "rrb"))
			return (false);
	while (o_c.rrr--)
		if (!r_rotate(s_a, s_b, o_l, "rrr"))
			return (false);
	return (true);
}
