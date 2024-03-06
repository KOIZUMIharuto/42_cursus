/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   under_six_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:59:02 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/03/06 17:27:03 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static t_ope	*under_three_sort(t_node **stack_a, int node_num);

t_ope	*under_six_sort(t_node **stack_a, t_node **stack_b, int node_num)
{
	t_ope	*ope_list;

	if (node_num <= 3)
		ope_list = under_three_sort(stack_a, node_num);
}

static t_ope	*under_three_sort(t_node **stack_a, int node_num)
{
	t_ope	*ope_list;
	char	*ope;

	if (node_num == 3)
	{
	}
}

// 1 2 ->
// 2 1 -> sa

// 1 2 3 ->
// 2 1 3 -> sa
// 2 3 1 -> rra
// 1 3 2 -> rra sa
// 3 1 2 -> ra 
// 3 2 1 -> ra sa
