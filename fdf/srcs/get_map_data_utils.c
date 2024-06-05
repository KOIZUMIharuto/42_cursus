/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_data_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 12:13:30 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/06/05 14:36:13 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static t_data	**recursive_split(char *row, double y, double x);
static void		set_data(t_data *data, t_vector4 *origin, unsigned int color);
static bool		atodbl_row(char **row, double *z, unsigned int *color);
static void		get_color(char **row, unsigned int *color);

t_data	***recursive_gnl(int fd, double y)
{
	char	*row;
	t_data	***data;

	row = get_next_line(fd);
	if (row)
	{
		data = recursive_gnl(fd, y + 1);
		if (data)
			data[(int)y] = recursive_split(row, y, 0);
		free (row);
		if (!data || !data[(int)y])
			return (free_data3(data, (int)y + 1));
	}
	else
	{
		data = (t_data ***)ft_calloc(y + 1, sizeof(t_data **));
		if (!data)
			return (return_error_null(strerror(errno)));
		data[(int)y] = NULL;
	}
	return (data);
}

static t_data	**recursive_split(char *row, double y, double x)
{
	t_data			**data;
	double			z;
	unsigned int	color;

	if (*row)
	{
		if (!atodbl_row(&row, &z, &color))
			return (return_error_null(ATODBL_ERROR_MESSAGE));
		data = recursive_split(row, y, x + 1);
		if (data)
			data[(int)x] = (t_data *)ft_calloc(1, sizeof(t_data));
		if (!data || !data[(int)x])
			return (free_data2(data));
		set_data(data[(int)x], create_vector4(x, y, z, 1), color);
		if (!data[(int)x]->origin || !data[(int)x]->fixed)
			return (free_data2(data));
	}
	else
	{
		data = (t_data **)ft_calloc(x + 1, sizeof(t_data *));
		if (!data)
			return (return_error_null(strerror(errno)));
		data[(int)x] = NULL;
	}
	return (data);
}

static void	set_data(t_data *data, t_vector4 *origin, unsigned int color)
{
	data->origin = origin;
	data->fixed = create_vector4(0, 0, 0, 1);
	data->color = color;
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
		if (*z < DBL_MIN / 10 || DBL_MAX / 10 < *z)
			return (false);
		*z *= 10;
		if (*z < DBL_MIN + (**row - '0')
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
