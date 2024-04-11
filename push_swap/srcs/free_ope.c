/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_ope.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 14:57:29 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/03/14 18:59:14 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	sub_free_ope_l_func(t_ope *ope_l);

t_ope	*free_ope_list(t_ope *ope_l_1, t_ope *ope_l_2)
{
	sub_free_ope_l_func(ope_l_1);
	sub_free_ope_l_func(ope_l_2);
	return (NULL);
}

static void	sub_free_ope_l_func(t_ope *ope_l)
{
	t_ope	*ope_tmp;

	while (ope_l)
	{
		ope_tmp = ope_l->next;
		free(ope_l);
		ope_l = ope_tmp;
	}
}

void	free_ope_dict(t_ope_ds *ope_ds)
{
	if (!ope_ds)
		return ;
	if (ope_ds->a)
		free(ope_ds->a);
	if (ope_ds->b)
		free(ope_ds->b);
	if (ope_ds->ab)
		free(ope_ds->ab);
	free(ope_ds);
}

t_ope	*free_s_ope(t_node *s_a, t_node *s_b, t_ope *ope_1, t_ope *ope_2)
{
	free_stack__exit(s_a, s_b, -1);
	(void)free_ope_list(ope_1, ope_2);
	return (NULL);
}
