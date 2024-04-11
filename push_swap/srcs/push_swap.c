/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 19:21:27 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/03/14 20:00:47 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void		ope_l_printer(t_ope *ope_l);
static size_t	ft_strlen(const char *s);

void	push_swap(t_node **s_a, t_node **s_b, int num)
{
	t_ope		*ope_l;
	t_ope_ds	*ope_ds;

	ope_l = NULL;
	ope_ds = init_ope_dict();
	if (!ope_ds)
		free_stack__exit(*s_a, *s_b, 1);
	if (num <= 3)
		ope_l = under_3(s_a, ope_ds->a);
	else if (num <= 6)
		ope_l = under_6(s_a, s_b, ope_ds);
	else
		ope_l = over_6(s_a, s_b, ope_ds, ope_l);
	if (!is_all_sorted(*s_a, *s_b)
		|| !format_ope_list(&ope_l, ope_ds))
	{
		free_ope_dict(ope_ds);
		free_ope_list(ope_l, NULL);
		free_stack__exit(*s_a, *s_b, 1);
	}
	free_ope_dict(ope_ds);
	ope_l_printer(ope_l);
	(void)free_ope_list(ope_l, NULL);
}

static void	ope_l_printer(t_ope *ope_l)
{
	while (ope_l)
	{
		write(1, ope_l->ope, ft_strlen(ope_l->ope));
		write(1, "\n", 1);
		ope_l = ope_l->next;
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
