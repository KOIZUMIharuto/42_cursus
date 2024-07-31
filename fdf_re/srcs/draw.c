/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:33:25 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/07/31 13:02:03 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void		init_z_buffer(double **z_buf);
static bool		checker(t_vector p0, t_vector p1);
static t_dot	*get_dot_by_index(t_list *map, int x, int y);

int	draw(t_vars *vars)
{
	int		x;
	int		y;
	t_dot	*dot;
	t_dot	*right_dot;
	t_dot	*bottom_dot;

	ft_bzero(vars->img.addr, HEIGHT * vars->img.line_length);
	init_z_buffer(vars->z_buf);
	y = -1;
	while (++y == 0 || bottom_dot)
	{
		x = -1;
		while (++x == 0 || right_dot)
		{
			dot = get_dot_by_index(vars->map, x, y);
			right_dot = get_dot_by_index(vars->map, x + 1, y);
			if (right_dot && checker(dot->fixed, right_dot->fixed))
				draw_line(vars, dot, right_dot);
			bottom_dot = get_dot_by_index(vars->map, x, y + 1);
			if (bottom_dot && checker(dot->fixed, bottom_dot->fixed))
				draw_line(vars, dot, bottom_dot);
		}
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	return (0);
}

static void	init_z_buffer(double **z_buf)
{
	int	x;
	int	y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
			z_buf[y][x] = -DBL_MAX;
	}
}

static t_dot	*get_dot_by_index(t_list *map, int x, int y)
{
	t_list	*row;

	while (map && y-- > 0)
		map = map->next;
	if (!map)
		return (NULL);
	row = (t_list *)(map->content);
	while (row && x-- > 0)
		row = row->next;
	if (!row)
		return (NULL);
	return ((t_dot *)(row->content));
}

static bool	checker(t_vector p0, t_vector p1)
{
	double	slope;
	double	y_intcpt;
	double	width_intcpt;

	if ((0 <= p0.x && p0.x < WIDTH && 0 <= p0.y && p0.y < HEIGHT)
		|| (0 <= p1.x && p1.x < WIDTH && 0 <= p1.y && p1.y < HEIGHT))
		return (true);
	if ((p0.x < 0 && p1.x < 0) || (p0.x >= WIDTH && p1.x >= WIDTH)
		|| (p0.y < 0 && p1.y < 0) || (p0.y >= HEIGHT && p1.y >= HEIGHT))
		return (false);
	if (p0.x == p1.x)
		return (0 <= p0.x && p0.x < WIDTH);
	else if (p0.y == p1.y)
		return (0 <= p0.y && p0.y < HEIGHT);
	else
	{
		slope = (p1.y - p0.y) / (p1.x - p0.x);
		y_intcpt = p0.y - slope * p0.x;
		width_intcpt = slope * WIDTH + y_intcpt;
		return ((slope >= 0 && y_intcpt < HEIGHT && width_intcpt > 0)
			|| (slope < 0 && width_intcpt < HEIGHT && y_intcpt > 0));
	}
}
