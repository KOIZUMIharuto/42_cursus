/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:16:16 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/04/17 14:16:19 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	get_ope_and_exec(t_node **s_a, t_node **s_b);
static bool	exec_ope(t_node **s_a, t_node **s_b, char *line);
static bool	ft_strcmp(char *s1, char *s2);

int	main(int argc, char *argv[])
{
	t_node	*s_a;
	t_node	*s_b;

	s_a = NULL;
	s_b = NULL;
	if (argc == 1)
		return (0);
	else
		create_stack(&s_a, &s_b, argc, argv);
	get_ope_and_exec(&s_a, &s_b);
	if (is_sorted(s_a) && node_counter(s_b) == 0)
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
	free_stack__exit(s_a, s_b, 0);
	return (0);
}

static void	get_ope_and_exec(t_node **s_a, t_node **s_b)
{
	char	*line;

	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		if (!exec_ope(s_a, s_b, line))
		{
			free(line);
			free_stack__exit(*s_a, *s_b, 1);
		}
		free(line);
	}
}

static bool	exec_ope(t_node **s_a, t_node **s_b, char *line)
{
	if (ft_strcmp(line, "sa\n"))
		return (swap(s_a, s_b, NULL, "sa"));
	else if (ft_strcmp(line, "sb\n"))
		return (swap(s_a, s_b, NULL, "sb"));
	else if (ft_strcmp(line, "ss\n"))
		return (swap(s_a, s_b, NULL, "ss"));
	else if (ft_strcmp(line, "pa\n"))
		return (push(s_b, s_a, NULL, "pa"));
	else if (ft_strcmp(line, "pb\n"))
		return (push(s_a, s_b, NULL, "pb"));
	else if (ft_strcmp(line, "ra\n"))
		return (rotate(s_a, s_b, NULL, "ra"));
	else if (ft_strcmp(line, "rb\n"))
		return (rotate(s_a, s_b, NULL, "rb"));
	else if (ft_strcmp(line, "rr\n"))
		return (rotate(s_a, s_b, NULL, "rr"));
	else if (ft_strcmp(line, "rra\n"))
		return (r_rotate(s_a, s_b, NULL, "rra"));
	else if (ft_strcmp(line, "rrb\n"))
		return (r_rotate(s_a, s_b, NULL, "rrb"));
	else if (ft_strcmp(line, "rrr\n"))
		return (r_rotate(s_a, s_b, NULL, "rrr"));
	return (false);
}

static bool	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (false);
		s1++;
		s2++;
	}
	if (*s1 || *s2)
		return (false);
	return (true);
}

// void	stack_printer(t_node *s_a, t_node *s_b) // for debug
// {
// 	t_node	*s_tmp;

// 	ft_printf("stack a\n");
// 	s_tmp = s_a;
// 	for(int i = 0; i < node_counter(s_a) + 1; i++)
// 	{
// 		ft_printf ("%d : %d[%d]\n", i, s_tmp->num, s_tmp->index);
// 		s_tmp = s_tmp->next;
// 	}
// 	ft_printf("stack b\n");
// 	s_tmp = s_b;
// 	for(int i = 0; i < node_counter(s_b) + 1; i++)
// 	{
// 		ft_printf ("%d : %d[%d]\n", i, s_tmp->num, s_tmp->index);
// 		s_tmp = s_tmp->next;
// 	}
// 	write(1, "\n", 1);
// }
