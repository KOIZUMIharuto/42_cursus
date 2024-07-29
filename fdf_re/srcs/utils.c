/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 12:23:34 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/07/29 16:11:35 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	update_min_max(t_vector vector, t_vector *min, t_vector *max);


bool	fdf_atoi(const char *str, int *result)
{
	int		sign;

	if (!str)
		return (false);
	while (('\t' <= *str && *str <= '\r') || *str == ' ')
		str++;
	sign = 1;
	if ((*str == '-' || *str == '+'))
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	*result = 0;
	while ('0' <= *str && *str <= '9')
	{
		if (*result < (INT64_MIN + (*str - '0')) / 10
			|| (INT64_MAX - (*str - '0')) / 10 < *result)
			return (false);
		*result *= 10;
		*result += sign * (*(str++) - '0');
	}
	return (true);
}

void	get_center(t_list *map, t_vector *center)
{
	t_vector	min;
	t_vector	max;
	t_list		*row;
	t_dot		*dot;

	min = (t_vector){DBL_MAX, DBL_MAX, DBL_MAX};
	max = (t_vector){-DBL_MAX, -DBL_MAX, -DBL_MAX};
	while (map)
	{
		row = (t_list *)(map->content);
		while (row)
		{
			dot = (t_dot *)(row->content);
			update_min_max(dot->fixed, &min, &max);
			row = row->next;
		}
		map = map->next;
	}
	*center = (t_vector){(max.x + min.x) / 2, (max.y + min.y) / 2,
		(max.z + min.z) / 2};
}

static void	update_min_max(t_vector vector, t_vector *min, t_vector *max)
{
	if (vector.x < min->x)
		min->x = vector.x;
	if (vector.x > max->x)
		max->x = vector.x;
	if (vector.y < min->y)
		min->y = vector.y;
	if (vector.y > max->y)
		max->y = vector.y;
	if (vector.z < min->z)
		min->z = vector.z;
	if (vector.z > max->z)
		max->z = vector.z;
}

double	rad(double deg)
{
	return (deg * M_PI / 180);
}
