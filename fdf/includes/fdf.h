/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxx <xxxx@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 12:03:27 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/06/07 17:26:22 by xxxx             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <float.h>
# include <fcntl.h>
# include <errno.h>
# include <stdio.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <math.h>

#include "../minilibx_macos/mlx.h"
# include "../libft/includes/libft.h"

# define USAGE_ERROR_MESSAGE "Error: Missing required argument.\n\
Usage: ./fdf <path_to_map_file>"
# define ATODBL_ERROR_MESSAGE "Error: Invalid value in map."
# define COLUMN_ERROR_MESSAGE "Error: Invalid column count."


# define WIDTH 900
# define HEIGHT 600

# define KEY_ESC 53

# define ON_MOUSEDOWN 4
# define ON_MOUSEUP 5
# define ON_MOUSEMOVE 6

# define LEFT 1
# define RIGHT 2
# define SCLOLL_UP 4
# define SCLOLL_DOWN 5

# define ON_EXPOSE 12
# define ON_DESTROY 17

# define UPPER_HEX_LIST "0123456789ABCDEF"
# define LOWER_HEX_LIST "0123456789abcdef"

typedef struct s_vector4
{
	double			x;
	double			y;
	double			z;
	double			w;
}	t_vector4;

typedef struct s_map
{
	t_vector4		*base;
	t_vector4		*fixed;
	unsigned int	color;
}	t_map;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

typedef struct s_vars
{
	t_map		***map;
	void		*mlx;
	void		*win;
	t_data		img;
	t_vector4	*pre_mouse;
}			t_vars;

t_map		***get_map(char	*map_file);
t_map		***recursive_gnl(int fd, double y);

t_vector4	*create_vector4(double x, double y, double z, double w);
bool		get_center(t_map ***map, t_vector4 *center_pos);
double		rad(double deg);

bool		trans(t_map ***map, t_vector4 *vector, bool is_free, bool rev);
bool		scale(t_map ***map, t_vector4 *vector, bool is_free, bool rev);
bool		rotate(t_map ***map, t_vector4 *vector, bool is_free, bool rev);

void		mymlx_main(t_map ***map);

int			mouse_move(int x, int y, t_vars *vars);
int			mouse_down(int key, int x, int y, t_vars *vars);
int			mouse_up(int key, int x, int y, t_vars *vars);


void		*free_map3(t_map ***map, int free_index);
void		*free_map2(t_map **map);
void		*free_map(t_map *map);

void		*return_error_null(char *error_message);

#endif
