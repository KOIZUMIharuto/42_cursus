/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxx <xxxx@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 12:13:30 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/06/06 16:28:35 by xxxx             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static t_map	**recursive_split(char *row, double y, double x);
static void		set_data(t_map *map, t_vector *base, unsigned int color);
static bool		atodbl_row(char **row, double *z, unsigned int *color);
static void		get_color(char **row, unsigned int *color);

t_map	***recursive_gnl(int fd, double y)
{
	char	*row;
	t_map	***map;

	row = get_next_line(fd);
	if (row)
	{
		map = recursive_gnl(fd, y + 1);
		if (map)
			map[(int)y] = recursive_split(row, y, 0);
		free (row);
		if (!map || !map[(int)y])
			return (free_map3(map, (int)y + 1));
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
			return (return_error_null(ATODBL_ERROR_MESSAGE));
		map = recursive_split(row, y, x + 1);
		if (map)
			map[(int)x] = (t_map *)ft_calloc(1, sizeof(t_map));
		if (!map || !map[(int)x])
			return (free_map2(map));
		set_data(map[(int)x], create_vector4(x, y, z, 1), color);
		if (!map[(int)x]->base || !map[(int)x]->fixed)
			return (free_map2(map));
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
		return (false);
	*z = sign * (*((*row)++) - '0');
	while ('0' <= **row && **row <= '9')
	{
		if (*z < -DBL_MAX / 10 || DBL_MAX / 10 < *z)
			return (false);
		*z *= 10;
		if (*z < -DBL_MAX + (**row - '0')
			|| DBL_MAX - (**row - '0') < *z)
			return (false);
		*z += sign * (*((*row)++) - '0');
	}
	get_color(row, color);
	while (**row == ' ' || **row == '\n')
		(*row)++;
	return (true);
}

static void	get_color(char **row, unsigned int *color)
{
	int	i;

	if (**row != ',')
		*color = 0xFFFFFF;
	else
	{
		(*row) += 3;
		*color = 0;
		while (ft_strchr(UPPER_HEX_LIST, **row)
			|| ft_strchr(LOWER_HEX_LIST, **row))
		{
			*color *= 16;
			i = 0;
			while (UPPER_HEX_LIST[i] != **row && LOWER_HEX_LIST[i] != **row)
				i++;
			*color += i;
			(*row)++;
		}
	}
}
