/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_ope_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxx <xxxx@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 12:37:59 by xxxx              #+#    #+#             */
/*   Updated: 2024/03/13 14:02:47 by xxxx             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ofset_ope_list(t_ope *ope_list);
static void	compress_ope_list(
	t_ope *ope_list, char *ope_a, char *ope_b, char *ope_ab);
static bool ope_set_checker(
	t_ope ope_1, t_ope ope_2, char *opename_1, char *opename_2);

bool	format_ope_list(t_ope **ope_list, t_all_ope_d *ope_d)
{
	if (!ope_list || !*ope_list || !ope_d)
		return (false);
	ofset_ope_list(*ope_list);
	compress_ope_list(*ope_list, ope_d->a->r, ope_d->b->r, ope_d->ab->r);
	compress_ope_list(*ope_list, ope_d->a->rr, ope_d->b->rr, ope_d->ab->rr);
	compress_ope_list(*ope_list, ope_d->a->s, ope_d->b->s, ope_d->ab->s);
	return (true);
}

static void	ofset_ope_list(t_ope *ope_list)
{
	t_ope	*ope_1;
	t_ope	*ope_2;

	ope_1 = ope_list;
	ope_2 = ope_list->next;
	while (ope_2)
	{
		if (ope_set_checker(*ope_1, *ope_2, "pa", "pb")
			|| ope_set_checker(*ope_1, *ope_2, "ra", "rra")
			|| ope_set_checker(*ope_1, *ope_2, "rb", "rrb"))
		{
			ope_1->prev->next = ope_2->next;
			if (ope_2->next)
				ope_2->next->prev = ope_1->prev;
			free(ope_1);
			ope_1 = ope_2->next;
			free(ope_2);
		}
		else
			ope_1 = ope_1->next;
		ope_2 = ope_1->next;
	}
}

static void	compress_ope_list(
	t_ope *ope_list, char *ope_a, char *ope_b, char *ope_ab)
{
	t_ope	*ope_1;
	t_ope	*ope_2;

	ope_1 = ope_list;
	ope_2 = ope_1->next;
	while (ope_2)
	{
		if (ope_set_checker(*ope_1, *ope_2, ope_a, ope_b))
		{
			ope_1->ope = ope_ab;
			ope_1->next = ope_2->next;
			if (ope_2->next)
				ope_2->next->prev = ope_1;
			free(ope_2);
			ope_1 = ope_2->next;
			ope_2 = ope_1->next;
		}
		else
		{
			ope_1 = ope_1->next;
			ope_2 = ope_2->next;
		}
	}
}

static bool ope_set_checker(
	t_ope ope_1, t_ope ope_2, char *opename_1, char *opename_2)
{
	if ((ft_strcmp(ope_1.ope, opename_1) && ft_strcmp(ope_2.ope, opename_2))
		|| (ft_strcmp(ope_1.ope, opename_2) && ft_strcmp(ope_2.ope, opename_1)))
		return (true);
	return (false);
}