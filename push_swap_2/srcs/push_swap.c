/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 19:21:27 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/03/31 11:32:41 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_swap(t_node **s_a, t_node **s_b, long num)
{
	t_ope		*ope_l;

	ope_l = NULL;
	(void)s_a;
	(void)s_b;
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
