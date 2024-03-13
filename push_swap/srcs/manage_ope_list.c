/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_ope_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxx <xxxx@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:45:57 by xxxx              #+#    #+#             */
/*   Updated: 2024/03/13 14:19:07 by xxxx             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void init_ope_str(char **ope, char *ope_name);

int	add_ope_list(t_ope **ope_list, char *ope)
{
	t_ope	*new_ope;
	t_ope	*ope_tmp;

	new_ope = (t_ope *)malloc(sizeof(t_ope));
	if (!new_ope)
	{
		free_ope_list(*ope_list, NULL);
		return (0);
	}
	new_ope->ope = ope;
	new_ope->prev = NULL;
	new_ope->next = NULL;
	if (!*ope_list)
	{
		*ope_list = new_ope;
		return (1);
	}
	ope_tmp = *ope_list;
	while (ope_tmp->next)
		ope_tmp = ope_tmp->next;
	ope_tmp->next = new_ope;
	new_ope->prev = ope_tmp;
	return (1);
}

void	join_ope_list(t_ope **ope_list, t_ope *new_ope)
{
	t_ope	*ope_tmp;

	if (!ope_list || !new_ope)
		return ;
	if (!*ope_list)
	{
		*ope_list = new_ope;
		return ;
	}
	ope_tmp = *ope_list;
	while (ope_tmp->next)
		ope_tmp = ope_tmp->next;
	ope_tmp->next = new_ope;
	new_ope->prev = ope_tmp;
}

t_all_ope_d *init_ope_dict(void)
{
	t_all_ope_d	*ope_d;

	ope_d = (t_all_ope_d *)malloc(sizeof(t_all_ope_d));
	if (!ope_d)
		return (NULL);
	ope_d->a = (t_ope_d *)malloc(sizeof(t_ope_d));
	ope_d->b = (t_ope_d *)malloc(sizeof(t_ope_d));
	ope_d->ab = (t_ope_d *)malloc(sizeof(t_ope_d));
	if (!ope_d->a || !ope_d->b || !ope_d->ab)
		return (NULL);
	init_ope_str(&(ope_d->a->s), "sa");
	init_ope_str(&(ope_d->a->p), "pb");
	init_ope_str(&(ope_d->a->r), "ra");
	init_ope_str(&(ope_d->a->rr), "rra");
	init_ope_str(&(ope_d->b->s), "sb");
	init_ope_str(&(ope_d->b->p), "pa");
	init_ope_str(&(ope_d->b->r), "rb");
	init_ope_str(&(ope_d->b->rr), "rrb");
	init_ope_str(&(ope_d->ab->s), "ss");
	init_ope_str(&(ope_d->ab->p), "");
	init_ope_str(&(ope_d->ab->r), "rr");
	init_ope_str(&(ope_d->ab->rr), "rrr");
	return (ope_d);
}

static void init_ope_str(char **ope, char *ope_name)
{
	*ope = ope_name;
}
