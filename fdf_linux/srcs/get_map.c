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

static t_map	**recursive_split(char *row, double y, double x);
static void		set_data(t_map *map, t_vector *base, unsigned int color);
static bool		atodbl_row(char **row, double *z, unsigned int *color);
static bool		get_col(char **row, unsigned int *color);

t_map	***get_map(int fd, double y)
{
	char	*row;
	t_map	***map;

	row = get_next_line(fd);
	if (row)
	{
		map = get_map(fd, y + 1);
		if (map)
			map[(int)y] = recursive_split(row, y, 0);
		free (row);
		if (!map || !map[(int)y])
			return (free_map3(map, (int)y + 1, NULL));
	}
	else
	{
		map = (t_map ***)ft_calloc(y + 1, sizeof(t_map **));
		if (!map)
			return (return_error_null(strerror(errno)));
		map[(int)y] = NULL;
	}
	return (map);
}

static t_map	**recursive_split(char *row, double y, double x)
{
	t_map			**map;
	double			z;
	unsigned int	color;

	if (*row)
	{
		if (!atodbl_row(&row, &z, &color))
			return (NULL);
		map = recursive_split(row, y, x + 1);
		if (map)
			map[(int)x] = (t_map *)ft_calloc(1, sizeof(t_map));
		if (!map || !map[(int)x])
			return (free_map2(map, NULL));
		set_data(map[(int)x], create_vector4(x, y, z, 1), color);
		if (!map[(int)x]->base || !map[(int)x]->fixed)
			return (free_map2(map, NULL));
	}
	else
	{
		map = (t_map **)ft_calloc(x + 1, sizeof(t_map *));
		if (!map)
			return (return_error_null(strerror(errno)));
		map[(int)x] = NULL;
	}
	return (map);
}

static void	set_data(t_map *map, t_vector *base, unsigned int color)
{
	map->base = base;
	map->fixed = create_vector4(base->x, base->y, base->z, base->w);
	map->color = color;
}

static bool	atodbl_row(char **row, double *z, unsigned int *color)
{
	int	sign;

	sign = 1;
	while (**row == ' ' || **row == '-')
	{
		sign *= -1;
		(*row)++;
	}
	if ((**row < '0' || '9' < **row))
		return (return_error_bool(ALTITUDE_ERROR_MESSAGE));
	*z = sign * (*((*row)++) - '0');
	while ('0' <= **row && **row <= '9')
	{
		if (*z < -DBL_MAX / 10 || DBL_MAX / 10 < *z)
			return (return_error_bool(ALTITUDE_ERROR_MESSAGE));
		*z *= 10;
		if (*z < -DBL_MAX + (**row - '0') || DBL_MAX - (**row - '0') < *z)
			return (return_error_bool(ALTITUDE_ERROR_MESSAGE));
		*z += sign * (*((*row)++) - '0');
	}
	if (!get_col(row, color))
		return (return_error_bool(COLOR_ERROR_MESSAGE));
	while (**row == ' ' || **row == '\n')
		(*row)++;
	return (true);
}

static bool	get_col(char **row, unsigned int *color)
{
	int	i;

	if (**row != ',')
		*color = 0xFFFFFF;
	else
	{
		(*row) += 3;
		*color = 0;
		while (**row && (ft_strchr(UPPER_HEX_LIST, **row)
				|| ft_strchr(LOWER_HEX_LIST, **row)))
		{
			i = 0;
			while (UPPER_HEX_LIST[i] != **row && LOWER_HEX_LIST[i] != **row)
				i++;
			if (*color > ((unsigned int)0xFFFFFF - i) / 16)
				return (false);
			*color = 16 * *color + i;
			(*row)++;
		}
		if (**row && **row != ' ' && **row != '\n')
			return (false);
	}
	return (true);
}
