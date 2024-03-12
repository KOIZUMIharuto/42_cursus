/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_ope.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxx <xxxx@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 17:24:39 by xxxx              #+#    #+#             */
/*   Updated: 2024/03/12 22:47:28 by xxxx             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	sub_free_ope_list_func(t_ope *ope_list);

t_ope	*free_ope_list(t_ope *ope_list_1, t_ope *ope_list_2)
{
	sub_free_ope_list_func(ope_list_1);
	sub_free_ope_list_func(ope_list_2);
	return (NULL);
}

static void	sub_free_ope_list_func(t_ope *ope_list)
{
	t_ope	*ope_tmp;

	while (ope_list)
	{
		ope_tmp = ope_list->next;
		free(ope_list);
		ope_list = ope_tmp;
	}
}

void	free_ope_dict(t_all_ope_d *ope_d)
{
	if (!ope_d)
		return ;
	if (ope_d->a)
		free(ope_d->a);
	if (ope_d->b)
		free(ope_d->b);
	if (ope_d->ab)
		free(ope_d->ab);
	free(ope_d);
}
