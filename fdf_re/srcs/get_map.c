/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 12:13:30 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/07/31 12:36:44 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static bool		split_row(t_list **row_list, char *row, int y_index);
static t_list	*set_dot(char *value, int x, int y);
static bool		get_col(char *row, unsigned int *color);
static bool		check_column(t_list *map);

void	get_map(t_list **map, int fd)
{
	char	*row;
	int		y_index;
	t_list	*row_list;
	t_list	*row_node;

	y_index = -1;
	while (1)
	{
		row = get_next_line(fd);
		if (!row)
			break ;
		row_list = NULL;
		if (!split_row(&row_list, row, ++y_index))
			return (ft_lstclear(map, &free_map));
		row_node = ft_lstnew((void *)row_list);
		if (!row_node)
			return (ft_lstclear(map, &free_map));
		ft_lstadd_back(map, (void *)row_node);
	}
	if (check_column(*map))
		return ;
	ft_lstclear(map, &free_map);
	ft_putstr_fd("Error: ", 2);
	ft_putendl_fd(COLUMN_ERROR, 2);
}

static bool	split_row(t_list **row_list, char *row, int y_index)
{
	char	**value;
	int		x_index;
	t_list	*dot;

	value = ft_split(row, " \n");
	free (row);
	if (!value)
		return (return_error_bool(strerror(errno)));
	x_index = -1;
	while (value[++x_index])
	{
		dot = set_dot(value[x_index], x_index, y_index);
		free (value[x_index]);
		if (!dot)
		{
			while (value[++x_index])
				free(value[x_index]);
			free (value);
			ft_lstclear(row_list, free);
			return (false);
		}
		ft_lstadd_back(row_list, dot);
	}
	free (value);
	return (true);
}

static t_list	*set_dot(char *value, int x, int y)
{
	t_list	*dot;
	t_dot	*dot_data;
	int		z;

	if (!fdf_atoi(value, &z))
		return (return_error_null(ALTITUDE_ERROR));
	dot_data = (t_dot *)ft_calloc(1, sizeof(t_dot));
	if (!dot_data)
		return (return_error_null(strerror(errno)));
	dot_data->base = (t_vector){(double)x, (double)y, (double)z};
	dot_data->fixed = (t_vector){(double)x, (double)y, (double)z};
	if (!get_col(ft_strchr(value, ','), &dot_data->color))
	{
		free (dot_data);
		return (return_error_null(COLOR_ERROR));
	}
	dot = ft_lstnew((void *)dot_data);
	if (!dot)
	{
		free (dot_data);
		return (return_error_null(strerror(errno)));
	}
	return (dot);
}

static bool	get_col(char *row, unsigned int *color)
{
	int	i;

	if (!row)
		*color = 0xFFFFFF;
	else
	{
		row += 3;
		*color = 0;
		while (*row && (ft_strchr(UPPER_HEX_LIST, *row)
				|| ft_strchr(LOWER_HEX_LIST, *row)))
		{
			i = 0;
			while (UPPER_HEX_LIST[i] != *row && LOWER_HEX_LIST[i] != *row)
				i++;
			if (*color > ((unsigned int)0xFFFFFF - i) / 16)
				return (false);
			*color = 16 * *color + i;
			row++;
		}
		if (*row)
			return (false);
	}
	return (true);
}

static bool	check_column(t_list *map)
{
	int	x;
	int	x_tmp;

	x = ft_lstsize((t_list *)(map->content));
	map = map->next;
	while (map)
	{
		x_tmp = ft_lstsize((t_list *)(map->content));
		if (x != x_tmp)
			return (false);
		map = map->next;
	}
	return (true);
}
