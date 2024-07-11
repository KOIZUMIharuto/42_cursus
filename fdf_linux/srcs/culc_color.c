/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   culc_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 15:40:09 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/07/11 16:01:33 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static unsigned int	culc_red(unsigned int color);
static unsigned int	culc_green(unsigned int color);
static unsigned int	culc_blue(unsigned int color);

unsigned int	culc_color(t_map *p0, t_vector_int tmp, t_map *p1)
{
	double			len;
	double			progress;
	unsigned int	red;
	unsigned int	green;
	unsigned int	blue;

	len = hypot(p1->isome->x - p0->isome->x, p1->isome->y - p0->isome->y);
	progress = hypot(tmp.x - p0->isome->x, tmp.y - p0->isome->y) / len;
	red = (1 - progress) * culc_red(p0->color) + progress * culc_red(p1->color);
	green = (1 - progress) * culc_green(p0->color)
		+ progress * culc_green(p1->color);
	blue = (1 - progress) * culc_blue(p0->color)
		+ progress * culc_blue(p1->color);
	return ((red * 256 * 256) + (green * 256) + blue);
}

static unsigned int	culc_red(unsigned int color)
{
	return ((color / (256 * 256)) % 256);
}

static unsigned int	culc_green(unsigned int color)
{
	return ((color / 256) % 256);
}

static unsigned int	culc_blue(unsigned int color)
{
	return (color % 256);
}
