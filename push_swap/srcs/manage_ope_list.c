/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_ope_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 14:57:15 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/03/14 19:10:54 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	init_ope_str(char **ope, char *ope_name);

int	add_ope_list(t_ope **ope_l, char *ope)
{
	t_ope	*new_ope;
	t_ope	*ope_tmp;

	new_ope = (t_ope *)malloc(sizeof(t_ope));
	if (!new_ope)
	{
		(void)free_ope_list(*ope_l, NULL);
		return (0);
	}
	new_ope->ope = ope;
	new_ope->prev = NULL;
	new_ope->next = NULL;
	if (!*ope_l)
	{
		*ope_l = new_ope;
		return (1);
	}
	ope_tmp = *ope_l;
	while (ope_tmp->next)
		ope_tmp = ope_tmp->next;
	ope_tmp->next = new_ope;
	new_ope->prev = ope_tmp;
	return (1);
}

void	join_ope_list(t_ope **ope_l, t_ope *new_ope)
{
	t_ope	*ope_tmp;

	if (!ope_l || !new_ope)
		return ;
	if (!*ope_l)
	{
		*ope_l = new_ope;
		return ;
	}
	ope_tmp = *ope_l;
	while (ope_tmp->next)
		ope_tmp = ope_tmp->next;
	ope_tmp->next = new_ope;
	new_ope->prev = ope_tmp;
}

t_ope_ds	*init_ope_dict(void)
{
	t_ope_ds	*ope_ds;

	ope_ds = (t_ope_ds *)malloc(sizeof(t_ope_ds));
	if (!ope_ds)
		return (NULL);
	ope_ds->a = (t_ope_d *)malloc(sizeof(t_ope_d));
	ope_ds->b = (t_ope_d *)malloc(sizeof(t_ope_d));
	ope_ds->ab = (t_ope_d *)malloc(sizeof(t_ope_d));
	if (!ope_ds->a || !ope_ds->b || !ope_ds->ab)
		return (NULL);
	init_ope_str(&(ope_ds->a->s), "sa");
	init_ope_str(&(ope_ds->a->p), "pb");
	init_ope_str(&(ope_ds->a->r), "ra");
	init_ope_str(&(ope_ds->a->rr), "rra");
	init_ope_str(&(ope_ds->b->s), "sb");
	init_ope_str(&(ope_ds->b->p), "pa");
	init_ope_str(&(ope_ds->b->r), "rb");
	init_ope_str(&(ope_ds->b->rr), "rrb");
	init_ope_str(&(ope_ds->ab->s), "ss");
	init_ope_str(&(ope_ds->ab->p), "");
	init_ope_str(&(ope_ds->ab->r), "rr");
	init_ope_str(&(ope_ds->ab->rr), "rrr");
	return (ope_ds);
}

static void	init_ope_str(char **ope, char *ope_name)
{
	*ope = ope_name;
}
