/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 12:13:30 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/05/30 15:47:26 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static t_data	***recursive_gnl(int fd, int row_count);
static t_data	**recursive_split(char *row, int y, int x);
static bool		atoi_row(char **row, int *z, unsigned int *color);
static void		set_color(char **row, unsigned int *color);

t_data	***get_map_data(char	*map_file)
{
	int		fd;
	t_data	***data;

	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		return (NULL);
	data = recursive_gnl(fd, 0);
	return (data);
}

static t_data	***recursive_gnl(int fd, int row_count)
{
	char	*row;
	t_data	***data;

	row = get_next_line(fd);
	if (row)
	{
		data = recursive_gnl(fd, row_count + 1);
		if (data)
			data[row_count] = recursive_split(row, row_count, 0);
		free (row);
		if (!data || !data[row_count])
			return (free_data(data));
	}
	else
	{
		data = (t_data ***)ft_calloc(row_count + 1, sizeof(t_data **));
		if (!data)
			return (NULL);
		data[row_count] = NULL;
	}
	return (data);
}

static t_data	**recursive_split(char *row, int y, int x)
{
	t_data			**data;
	int				z;
	unsigned int	color;

	if (*row)
	{
		while (*row == ' ' || *row == '\n')
			row++;
		if (!atoi_row(&row, &z, &color))
			return (NULL);
		data = recursive_split(row, y, x + 1);
		if (data)
			data[x] = (t_data *)malloc(sizeof(t_data));
		if (!data || !data[x])
			return (free_data(&data));
		*(data[x]) = (t_data){x, y, z, color};
	}
	else
	{
		data = (t_data **)ft_calloc(x + 1, sizeof(t_data *));
		if (!data)
			return (NULL);
		data[x] = NULL;
	}
	return (data);
}

static bool	atoi_row(char **row, int *z, unsigned int *color)
{
	int	sign;

	sign = 1;
	if (**row == '-')
	{
		sign = -1;
		(*row)++;
	}
	if ((**row < '0' || '9' < **row))
		return (false);
	*z = sign * (*((*row)++) - '0');
	while ('0' <= **row && **row <= '9')
	{
		if (*z < INT_MIN / 10 || INT_MAX / 10 < *z)
			return (false);
		*z *= 10;
		if (*z < INT_MIN + (**row - '0')
			|| INT_MAX - (**row - '0') < *z)
			return (false);
		*z += sign * (*((*row)++) - '0');
	}
	set_color(row, color);
	while (**row == ' ' || **row == '\n')
		(*row)++;
	return (true);
}

static void	set_color(char **row, unsigned int *color)
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
