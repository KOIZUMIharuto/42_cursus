/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxx <xxxx@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 19:21:27 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/04/05 02:04:35 by xxxx             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	print_ope_l(t_ope_l *ope_l);
static bool free_ope_l(t_ope_l *ope_l, bool ret);

bool	push_swap(t_node **s_a, t_node **s_b)
{
	t_ope_l		*ope_l;

	ope_l = NULL;
	(void)s_b;
	if (node_counter(*s_a) <= 3)
	{
		if (!under_3_sort(s_a, &ope_l))
			return (free_ope_l(ope_l, false));
	}
	else
	{
		if (!insert_sort(s_a, s_b, &ope_l))
			return (free_ope_l(ope_l, false));
	}
	print_ope_l(ope_l);
	return (free_ope_l(ope_l, true));
}

static void	print_ope_l(t_ope_l *ope_l)
{
	while (ope_l)
	{
		ft_putendl_fd(ope_l->ope, 1);
		ope_l = ope_l->next;
	}
}

static bool free_ope_l(t_ope_l *ope_l, bool ret)
{
	t_ope_l	*tmp;

	while (ope_l)
	{
		tmp = ope_l->next;
		free(ope_l);
		ope_l = tmp;
	}
	return (ret);
}