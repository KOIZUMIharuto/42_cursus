/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxx <xxxx@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 19:21:27 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/03/13 14:45:27 by xxxx             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ope_list_printer(t_ope *ope_list);
static size_t	ft_strlen(const char *s);

void	push_swap(t_node **stack_a, t_node **stack_b, int node_num)
{
	t_ope		*ope_list;
	t_all_ope_d	*ope_dict;

	ope_dict = init_ope_dict();
	if (!ope_dict)
		free_stack__exit(*stack_a, *stack_b, 1);
	if (node_num <= 3)
		ope_list = under_3_sort(stack_a, ope_dict->a);
	else if (node_num <= 6)
		ope_list = under_6_sort(stack_a, stack_b, node_num, ope_dict);
	else
		ope_list = algorithm_sort(stack_a, stack_b, ope_dict);
	if (!is_all_sorted(*stack_a, *stack_b, node_num)
		|| !format_ope_list(&ope_list, ope_dict))
	{
		(void)free_ope_list(ope_list, NULL);
		free_stack__exit(*stack_a, *stack_b, 1);
	}
	free_ope_dict(ope_dict);
	ope_list_printer(ope_list);
	(void)free_ope_list(ope_list, NULL);
}

static void	ope_list_printer(t_ope *ope_list)
{
	while (ope_list)
	{
		write(1, ope_list->ope, ft_strlen(ope_list->ope));
		write(1, "\n", 1);
		ope_list = ope_list->next;
	}
}

static size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	if (s)
		while (s[len])
			len++;
	return (len);
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
