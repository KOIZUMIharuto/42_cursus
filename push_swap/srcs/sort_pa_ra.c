/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_pa_ra.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 14:56:57 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/03/14 18:56:47 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_ope	*sort_pa_ra(
	t_node **s_a, t_node **s_b, t_ope_ds *ope_ds)
{
	t_ope	*ope_l;

	ope_l = under_3(s_b, ope_ds->b);
	while (node_counter(*s_b) > 0)
	{
		if (add_ope_list(&ope_l, ope_ds->b->p))
			push(s_b, s_a);
		if (add_ope_list(&ope_l, ope_ds->a->r))
			rotate(s_a, NULL);
	}
	return (ope_l);
}
