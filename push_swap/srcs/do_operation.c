/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   use_ope.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 16:33:35 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/03/06 16:57:18 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static bool	ft_strcmp(char *s_1, char *s_2);

void	do_ope(t_node **s_a, t_node **s_b, char *ope)
{
	if (ft_strcmp(ope, "sa"))
		swap(s_a, NULL);
	else if (ft_strcmp(ope, "sb"))
		swap(NULL, s_b);
	else if (ft_strcmp(ope, "ss"))
		swap(s_a, s_b);
	else if (ft_strcmp(ope, "pa"))
		push(s_b, s_a);
	else if (ft_strcmp(ope, "pb"))
		push(s_a, s_b);
	else if (ft_strcmp(ope, "ra"))
		rotate(s_a, NULL);
	else if (ft_strcmp(ope, "rb"))
		rotate(NULL, s_b);
	else if (ft_strcmp(ope, "rr"))
		rotate(s_a, s_b);
	else if (ft_strcmp(ope, "rra"))
		reverse_rotate(s_a, NULL);
	else if (ft_strcmp(ope, "rrb"))
		reverse_rotate(NULL, s_b);
	else if (ft_strcmp(ope, "rrr"))
		reverse_rotate(s_a, s_b);
}

static bool	ft_strcmp(char *s_1, char *s_2)
{
	if (!s_1 || !s_2)
		return (false);
	while (*s_1 || *s_2)
	{
		if (*s_1 != *s_2)
			return (false);
		s_1++;
		s_2++;
	}
	return (true);
}
