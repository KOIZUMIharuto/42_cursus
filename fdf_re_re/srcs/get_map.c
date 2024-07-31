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

static t_dot	*get_row(char *row, int y);
static bool		set_data(t_dot *dot, char **value, int y);
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
		map->dots[y] = get_row(row, y);
	free (row);
	if (!map->dots || !map->dots[y])
		return (free_map(map, NULL));
	return (map);
}

static t_dot	*get_row(char *row, int y)
{
	char	**value;
	int		x;
	t_dot	*dots;

	value = ft_split(row, " \n");
	if (!value)
		return (return_error_null(strerror(errno)));
	x = 0;
	while (value[x])
		x++;
	dots = (t_dot *)ft_calloc(x, sizeof(t_dot));
	if (!dots)
		return (return_error_null(strerror(errno)));
	if (!set_data(dots, value, y))
	{
		free (dots);
		dots = NULL;
	}
	x = -1;
	while (value[++x])
		free (value[x]);
	free (value);
	return (dots);
}

static bool	set_data(t_dot *dot, char **value, int y)
{
	int				x;
	int				z;
	unsigned int	color;


	x = -1;
	while (value[++x])
	{
		if (!fdf_atoi(value[x], &z))
			return (return_error_bool(ALTITUDE_ERROR));
		if (!get_color(value[x], &color))
			return (return_error_bool(COLOR_ERROR));
		dot[x].base = (t_vector){(double)x, (double)y, (double)z};
		dot[x].fixed = (t_vector){(double)x, (double)y, (double)z};
		dot[x].color = color;
	}
	return (true);
}


static bool	get_color(char *value, unsigned int *color)
{
	int	i;

	if (!value)
		*color = 0xFFFFFF;
	else
	{
		value += 3;
		*color = 0;
		while (*value && (ft_strchr(UPPER_HEX_LIST, *value)
				|| ft_strchr(LOWER_HEX_LIST, *value)))
		{
			i = 0;
			while (UPPER_HEX_LIST[i] != *value && LOWER_HEX_LIST[i] != *value)
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
