/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxx <xxxx@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 11:57:33 by xxxx              #+#    #+#             */
/*   Updated: 2024/04/05 01:22:00 by xxxx             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static bool		insert_sort_util(t_node **s_a, t_node **s_b, t_ope_l **ope_l);
static t_ope_c	count_ra_rra(t_node *s_a, long rb_count, long index);
static long		compress_and_sum(t_ope_c *ope_c);
static bool		do_ope(t_ope_c o_c, t_node **s_a, t_node **s_b, t_ope_l **o_l);

bool	insert_sort(t_node **s_a, t_node **s_b, t_ope_l **ope_l)
{
	long	min_num_index;
	while(node_counter(*s_a) > 3 && !is_almost_sorted(*s_a))
	{
		if (!push(s_a, s_b, ope_l, "pb"))
			return (false);
	}
	if (!is_almost_sorted(*s_a))
		if (!swap(s_a, s_b, ope_l, "sa"))
			return (false);
	while (node_counter(*s_b))
	{
		if (!insert_sort_util(s_a, s_b, ope_l))
			return (false);
	}
	ft_putendl_fd("min_num_index", 1);
	min_num_index = get_index_index(*s_a, get_min_num_index(*s_a));
	if (min_num_index < node_counter(*s_a) - min_num_index)
	{
		while (min_num_index--)
		{
			ft_putendl_fd("ra", 1);
			if (!rotate(s_a, s_b, ope_l, "ra"))
				return (false);
		}
	}
	else
	{
		while (node_counter(*s_a) - min_num_index++)
		{
			ft_putendl_fd("rra", 1);
			if (!r_rotate(s_a, s_b, ope_l, "rra"))
				return (false);
		}
	}
	return (true);
}

static bool	insert_sort_util(t_node **s_a, t_node **s_b, t_ope_l **ope_l)
{
	t_node	*s_b_tmp;
	t_ope_c	least_ope_count;
	t_ope_c	ope_count;
	long	rb_count;
	
	ft_putendl_fd("insert_sort_util start", 1);
	s_b_tmp = *s_b;
	rb_count = 0;
	least_ope_count = count_ra_rra(*s_a, rb_count, s_b_tmp->index);
	while (s_b_tmp->next->index != -1)
	{
		ft_putendl_fd("while start", 1);
		rb_count++;
		s_b_tmp = s_b_tmp->next;
		ope_count = count_ra_rra(*s_a, rb_count, get_min_num_index(*s_b));
		if (compress_and_sum(&ope_count) < compress_and_sum(&least_ope_count))
			least_ope_count = ope_count;
		ft_putendl_fd("while end", 1);
	}
	ft_putendl_fd("do_ope start", 1);
	if (!do_ope(least_ope_count, s_a, s_b, ope_l))
		return (false);
	ft_putendl_fd("do_ope end", 1);
	
	if (!push(s_a, s_b, ope_l, "pa"))
		return (false);
	ft_putendl_fd("insert_sort_util end", 1);
	return (true);
}

static t_ope_c	count_ra_rra(t_node *s_a, long rb_count, long index)
{
	t_ope_c	ope_count;
	long	ra_count;

	if (rb_count < node_counter(s_a) - rb_count)
		ope_count = (t_ope_c){0, rb_count, 0, 0, 0, 0};
	else
		ope_count = (t_ope_c){0, 0, 0, 0, node_counter(s_a) - rb_count, 0};
	ra_count = 0;
	if (index < s_a->index)
	{
		while (s_a->index != get_min_num_index(s_a))
		{
			ra_count++;
			rotate_util_func(&s_a);
		}
	}
	while (s_a->index < index)
	{
		ra_count++;
		rotate_util_func(&s_a);
	}
	if (ra_count < node_counter(s_a) - ra_count)
		ope_count.ra = ra_count;
	else
		ope_count.rra = node_counter(s_a) - ra_count;
	return (ope_count);
}

static long	compress_and_sum(t_ope_c *ope_c)
{
	long	sum;

	ft_putstr_fd("rrb:", 1);
	ft_putnbr_fd(ope_c->rrb, 1);
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
	{
		ft_putnbr_fd(o_c.ra, 1);
		ft_putendl_fd("ra", 1);
		if (!rotate(s_a, s_b, o_l, "ra"))
			return (false);
	}
		// if (!rotate(s_a, s_b, o_l, "ra"))
		// 	return (false);
	while (o_c.rb--)
	{
		ft_putnbr_fd(o_c.rb, 1);
		ft_putendl_fd("rb", 1);
		if (!rotate(s_a, s_b, o_l, "rb"))
			return (false);
	}
		// if (!rotate(s_a, s_b, o_l, "rb"))
		// 	return (false);
	while (o_c.rr--)
	{
		ft_putnbr_fd(o_c.rr, 1);
		ft_putendl_fd("rr", 1);
		if (!rotate(s_a, s_b, o_l, "rr"))
			return (false);
	}
		// if (!rotate(s_a, s_b, o_l, "rr"))
		// 	return (false);
	while (o_c.rra--)
	{
		ft_putnbr_fd(o_c.rra, 1);
		ft_putendl_fd("rra", 1);
		if (!r_rotate(s_a, s_b, o_l, "rra"))
			return (false);
	}
		// if (!r_rotate(s_a, s_b, o_l, "rra"))
		// 	return (false);
	ft_putnbr_fd(o_c.rrb, 1);
	while (o_c.rrb--)
	{
		// ft_putnbr_fd(o_c.rrb, 1);
		// ft_putendl_fd("rrb", 1);
		if (!r_rotate(s_a, s_b, o_l, "rrb"))
			return (false);
	}
		// if (!r_rotate(s_a, s_b, o_l, "rrb"))
		// 	return (false);
	while (o_c.rrr--)
	{
		ft_putnbr_fd(o_c.rrr, 1);
		ft_putendl_fd("rrr", 1);
		if (!r_rotate(s_a, s_b, o_l, "rrr"))
			return (false);
	}
		// if (!r_rotate(s_a, s_b, o_l, "rrr"))
		// 	return (false);
	return (true);
}