/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 19:21:27 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/03/28 18:50:18 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_swap(t_node **s_a, t_node **s_b, long num)
{
	t_ope		*ope_l;
	t_ope_ds	*ope_ds;

	ope_l = NULL;
	ope_ds = NULL;
	(void)s_a;
	(void)s_b;
	// if (!ope_ds)
	// 	free_stack__exit(*s_a, *s_b, 1);
	if (num <= 3)
		ope_l = NULL;
	else if (num <= 6)
		ope_l = NULL;
	else
		ope_l = NULL;
}

bool	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	if (!s1 || !s2)
		return (false);
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] == s2[i]);
}
