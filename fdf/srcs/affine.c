/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxx <xxxx@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 16:28:45 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/06/07 17:33:21 by xxxx             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void rotate_z(t_vector4 *vector, double angle);
static void rotate_y(t_vector4 *vector, double angle);
static void rotate_x(t_vector4 *vector, double angle);

bool	trans(t_map ***map, t_vector4 *vector, bool is_free, bool rev)
{
	int	x;
	int	y;
	int	dir;

	if (!vector)
		return (false);
	// printf("trans(%.2F, %.2F, %.2F)\n", vector->x, vector->y, vector->z);
	dir = 1 - 2 * (int)rev;
	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			map[y][x]->fixed->x += dir * vector->x;
			map[y][x]->fixed->y += dir * vector->y;
			map[y][x]->fixed->z += dir * vector->z;
		}
	}
	if (is_free)
		free(vector);
	return (true);
}

bool	scale(t_map ***map, t_vector4 *vector, bool is_free, bool rev)
{
	int	x;
	int	y;
	double	scale_x;
	double	scale_y;
	double	scale_z;

	if (!vector)
		return (false);
	// printf("scale(%.2F, %.2F, %.2F)\n", vector->x, vector->y, vector->z);
	scale_x = vector->x * (1 - (int)rev) + 1 / vector->x * (int)rev;
	scale_y = vector->y * (1 - (int)rev) + 1 / vector->y * (int)rev;
	scale_z = vector->z * (1 - (int)rev) + 1 / vector->z * (int)rev;
	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			map[y][x]->fixed->x *= scale_x;
			map[y][x]->fixed->y *= scale_y;
			map[y][x]->fixed->z *= scale_z;
		}
	}
	if (is_free)
		free(vector);
	return (true);
}

bool	rotate(t_map ***map, t_vector4 *vector, bool is_free, bool rev)
{
	int		x;
	int		y;

	if (!vector)
		return (false);
	// printf("rotate(%.2F, %.2F, %.2F)\n", vector->x, vector->y, vector->z);
	if (rev)
	{
		vector->x *= -1;
		vector->y *= -1;
		vector->z *= -1;
	}
	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			rotate_z(map[y][x]->fixed, vector->z);
			rotate_y(map[y][x]->fixed, vector->y);
			rotate_x(map[y][x]->fixed, vector->x);
		}
	}
	if (is_free)
		free(vector);
	return (true);
}

static void rotate_z(t_vector4 *vector, double angle)
{
    double tmp_x = vector->x;
    double tmp_y = vector->y;

    vector->x = tmp_x * cos(angle) - tmp_y * sin(angle);
    vector->y = tmp_x * sin(angle) + tmp_y * cos(angle);
}

static void rotate_y(t_vector4 *vector, double angle)
{
    double tmp_x = vector->x;
    double tmp_z = vector->z;

    vector->x = tmp_x * cos(angle) + tmp_z * sin(angle);
    vector->z = -tmp_x * sin(angle) + tmp_z * cos(angle);
}

static void rotate_x(t_vector4 *vector, double angle)
{
	double tmp_y = vector->y;
	double tmp_z = vector->z;

	vector->y = tmp_y * cos(angle) - tmp_z * sin(angle);
	vector->z = tmp_y * sin(angle) + tmp_z * cos(angle);
}

