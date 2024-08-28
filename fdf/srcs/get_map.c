/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 12:13:30 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/06/05 13:54:54 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static t_dot	*get_row(char *row, int y, int *x);
static bool		set_data(t_dot *dot, char **value, int y, int *x);
static void		free_value(char **value);
static bool		get_color(char *value, unsigned int *color);

void	get_map(t_map *map, int fd, int y)
{
	char	*row;

	row = get_next_line(fd);
	if (!row)
	{
		if (y == 0)
			return ((void)return_msg_null(EMPTY_MAP_ERROR, 2));
		map->dots = (t_dot **)ft_calloc(y, sizeof(t_dot *));
		if (!map->dots)
			return (perror("Error"));
		map->y = y;
		return ;
	}
	get_map(map, fd, y + 1);
	if (map->dots)
		map->dots[y] = get_row(row, y, &(map->x));
	free (row);
	if (!map->dots || !map->dots[y])
		return (free_map(map));
}

static t_dot	*get_row(char *row, int y, int *x)
{
	char	**value;
	int		x_index;
	t_dot	*dots;

	value = ft_split(row, " \n");
	if (!value)
		return (return_msg_null(strerror(errno), 2));
	x_index = 0;
	while (value[x_index])
		x_index++;
	dots = (t_dot *)ft_calloc(x_index, sizeof(t_dot));
	if (!dots)
	{
		free_value(value);
		return (return_msg_null(strerror(errno), 2));
	}
	if (!set_data(dots, value, y, x))
	{
		free (dots);
		dots = NULL;
	}
	free_value(value);
	return (dots);
}

static void	free_value(char **value)
{
	int	i;

	i = -1;
	while (value[++i])
		free (value[i]);
	free (value);
}

static bool	set_data(t_dot *dot, char **value, int y, int *x)
{
	int				x_index;
	int				z;
	unsigned int	color;

	x_index = -1;
	while (value[++x_index])
	{
		if (!fdf_atoi(value[x_index], &z))
			return (return_msg_bool(ALTITUDE_ERROR, 2));
		color = 0;
		if (!get_color(value[x_index], &color))
			return (return_msg_bool(COLOR_ERROR, 2));
		dot[x_index].base = (t_vector){(double)x_index, (double)y, (double)z};
		dot[x_index].fixed = (t_vector){(double)x_index, (double)y, (double)z};
		dot[x_index].color = color;
	}
	if (x_index == 0)
		return (return_msg_bool(EMPTY_LINE_ERROR, 1));
	if (*x != -1 && *x != x_index)
		return (return_msg_bool(COLUMN_ERROR, 2));
	*x = x_index;
	return (true);
}

static bool	get_color(char *value, unsigned int *color)
{
	int		i;

	value = ft_strchr(value, ',');
	if (!value)
		*color = 0xFFFFFF;
	else
	{
		if (ft_strncmp(value, ",0x", 3))
			return (false);
		value += 3;
		while (*value && (ft_strchr(UPPER_HEX, *value)
				|| ft_strchr(LOWER_HEX, *value)))
		{
			i = 0;
			while (UPPER_HEX[i] != *value && LOWER_HEX[i] != *value)
				i++;
			if (*color > ((unsigned int)0xFFFFFF - i) / 16)
				return (false);
			*color = 16 * *color + i;
			value++;
		}
		if (*value)
			return (false);
	}
	return (true);
}
