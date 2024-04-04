/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_ope_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxx <xxxx@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 11:20:17 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/04/05 01:03:34 by xxxx             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

bool	add_new_ope(t_ope_l **ope_l, char *ope)
{
	t_ope_l	*new_ope_l;

	if (!ope_l)
		return (false);
	new_ope_l = (t_ope_l *)malloc (sizeof(t_ope_l));
	if (!new_ope_l)
		return (false);
	if (!*ope_l)
	{
		*ope_l = new_ope_l;
		new_ope_l->next = NULL;
		new_ope_l->prev = new_ope_l;
	}
	else
	{
		new_ope_l->prev = (*ope_l)->prev;
		(*ope_l)->prev->next = new_ope_l;
		(*ope_l)->prev = new_ope_l;
		new_ope_l->next = NULL;
	}
	new_ope_l->ope = ope;
	return (true);
}
