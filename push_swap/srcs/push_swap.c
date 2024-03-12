/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxx <xxxx@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 19:21:27 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/03/12 22:55:22 by xxxx             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void		ope_list_printer(t_ope *ope_list);
static size_t	ft_strlen(const char *s);

void	push_swap(t_node **stack_a, t_node **stack_b, int node_num)
{
	t_ope		*ope_list;
	t_all_ope_d	*ope_dict;

	// printf("do push_swap !\n"); // delete
	(void)stack_a;
	(void)stack_b;
	(void)node_num;
	ope_dict = init_ope_dict();
	if (!ope_dict)
		free_stack__exit(*stack_a, *stack_b, 1);
	if (node_num <= 3)
		ope_list = under_3_sort(stack_a, node_num, ope_dict->a);
	else if (node_num <= 6)
		ope_list = under_6_sort(stack_a, stack_b, node_num, ope_dict);
	else
		ope_list = NULL;
	free_ope_dict(ope_dict);
	if (!is_all_sorted(*stack_a, *stack_b, node_num))
	{
		(void)free_ope_list(ope_list, NULL);
		free_stack__exit(*stack_a, *stack_b, 1);
	}
	// printf("\n"); // delete
	ope_list_printer(ope_list);
	// printf("\n"); // delete
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