/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_ope_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 11:20:17 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/03/31 12:48:53 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

bool	add_ope_list(t_ope **ope_l, char *ope)
{
	t_ope	*new_ope;

	new_ope = (t_ope *)malloc (sizeof(t_ope));
	if (!new_ope)
		return (false);
	if (!*ope_l)
	{
		*ope_l = new_ope;
		new_ope->next = NULL;
		new_ope->prev = new_ope;
	}
	else
	{
		new_ope->prev = (*ope_l)->prev;
		(*ope_l)->prev->next = new_ope;
		(*ope_l)->prev = new_ope;
		new_ope->next = NULL;
	}
	new_ope->ope = ft_strdup(ope);
	if (!new_ope->ope)
		return (false);
	return (true);
}

t_ope	*join_ope_list(t_ope **ope_l, t_ope *new_ope_l)
{
	t_ope	*ope_l_tmp;

	if (!ope_l)
		return (NULL);
	if (!*ope_l)
		*ope_l = new_ope_l;
	else
	{
		ope_l_tmp = (*ope_l)->prev; 
		(*ope_l)->prev = new_ope_l->prev;
		new_ope_l->prev = ope_l_tmp;
		ope_l_tmp->next = new_ope_l;
	}
	return (*ope_l);
}
