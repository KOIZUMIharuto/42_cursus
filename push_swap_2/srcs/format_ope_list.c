/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_ope_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxx <xxxx@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 14:57:34 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/04/04 14:26:13 by xxxx             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static bool	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	if (!s1 || !s2)
		return (false);
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] == s2[i]);
}

static bool	ope_set_checker(t_ope_l *ope_1, t_ope_l *ope_2, char *s_1, char *s_2)
{
	if ((ft_strcmp(ope_1->ope, s_1) && ft_strcmp(ope_2->ope, s_2))
		|| (ft_strcmp(ope_1->ope, s_2) && ft_strcmp(ope_2->ope, s_1)))
		return (true);
	return (false);
}

static bool	compress_ope_list(
	t_ope_l **ope_l, char *ope_a, char *ope_b, char *ope_ab)
{
	t_ope_l	*ope_1;
	t_ope_l	*ope_2;
	bool	is_formatted;

	ope_1 = ope_l;
	ope_2 = ope_1->next;
	is_formatted = true;
	while (ope_2)
	{
		if (ope_set_checker(ope_1, ope_2, ope_a, ope_b))
		{
			ope_1->ope = ope_ab;
			ope_1->next = ope_2->next;
			if (ope_2->next)
				ope_2->next->prev = ope_1;
			free(ope_2);
			ope_1 = ope_2->next;
			is_formatted = false;
		}
		else
			ope_1 = ope_1->next;
		ope_2 = ope_1->next;
	}
	return (is_formatted);
}

static bool	ofset_ope_list(t_ope_l **ope_l, bool is_formatted)
{
	t_ope_l	*ope_1;
	t_ope_l	*ope_2;

	ope_1 = ope_l;
	while (ope_1 && ope_1->next)
	{
		ope_2 = ope_1->next;
		if (ope_set_checker(ope_1, ope_2, "pa", "pb")
			|| ope_set_checker(ope_1, ope_2, "ra", "rra")
			|| ope_set_checker(ope_1, ope_2, "rb", "rrb"))
		{
			if (ope_1->prev)
				ope_1->prev->next = ope_2->next;
			if (ope_2->next)
				ope_2->next->prev = ope_1->prev;
			free(ope_1);
			ope_1 = ope_2->next;
			free(ope_2);
			is_formatted = false;
		}
		else
			ope_1 = ope_1->next;
	}
	return (is_formatted);
}

bool	format_ope_list(t_ope_l **ope_l)
{
	bool	is_formatted;

	if (!ope_l || !*ope_l)
		return (false);
	is_formatted = false;
	while (!is_formatted)
	{
		// if (ofset_ope_list(*ope_l, true)
		// 	&& compress_ope_list(
		// 		*ope_l, ope_ds->a->r, ope_ds->b->r, ope_ds->ab->r)
		// 	&& compress_ope_list(
		// 		*ope_l, ope_ds->a->rr, ope_ds->b->rr, ope_ds->ab->rr)
		// 	&& compress_ope_list(
		// 		*ope_l, ope_ds->a->s, ope_ds->b->s, ope_ds->ab->s))
		// 	is_formatted = true;
	}
	return (true);
}
