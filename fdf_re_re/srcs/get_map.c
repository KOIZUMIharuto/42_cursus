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

#include "../includes/fdf.h"

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
		return (free_map(map, NULL));
}

static t_dot	*get_row(char *row, int y, int *x)
{
	char	**value;
	int		x_index;
	t_dot	*dots;

	value = ft_split(row, " \n");
	if (!value)
		return (return_error_null(strerror(errno)));
	x_index = 0;
	while (value[x_index])
		x_index++;
	dots = (t_dot *)ft_calloc(x_index, sizeof(t_dot));
	if (!dots)
	{
		free_value(value);
		return (return_error_null(strerror(errno)));
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
			return (return_error_bool(ALTITUDE_ERROR));
		if (!get_color(value[x_index], &color))
			return (return_error_bool(COLOR_ERROR));
		dot[x_index].base = (t_vector){(double)x_index, (double)y, (double)z};
		dot[x_index].fixed = (t_vector){(double)x_index, (double)y, (double)z};
		dot[x_index].color = color;
	}
	if (*x != -1 && *x != x_index)
		return (return_error_bool(COLUMN_ERROR));
	*x = x_index;
	return (true);
}

static bool	get_color(char *value, unsigned int *color)
{
	int		i;
	char	*col_txt;

	col_txt = ft_strchr(value, ',');
	if (!col_txt)
		*color = 0xFFFFFF;
	else
	{
		col_txt += 3;
		*color = 0;
		while (*col_txt && (ft_strchr(UPPER_HEX, *col_txt)
				|| ft_strchr(LOWER_HEX, *col_txt)))
		{
			i = 0;
			while (UPPER_HEX[i] != *col_txt && LOWER_HEX[i] != *col_txt)
				i++;
			if (*color > ((unsigned int)0xFFFFFF - i) / 16)
				return (false);
			*color = 16 * *color + i;
			col_txt++;
		}
		if (*col_txt)
			return (false);
	}
	return (true);
}
