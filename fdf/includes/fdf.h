/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 12:03:27 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/06/17 17:51:38 by hkoizumi         ###   ########.fr       */
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

# include "../minilibx_macos/mlx.h"
# include "../libft/includes/libft.h"

# define USAGE_ERROR_MESSAGE "Error: Missing required argument.\n\
Usage: ./fdf <path_to_map_file>"
# define EXTENSION_ERROR_MESSAGE "Error: Invalid file extension.\n\
Required: .fdf file"
# define FILE_OPEN_ERROR_MESSAGE "Error: Failed to open file."
// # define ATODBL_ERROR_MESSAGE "Error: Invalid value in map."
# define ALTITUDE_ERROR_MESSAGE "Error: Invalid altitude in map."
# define COLOR_ERROR_MESSAGE "Error: Invalid color in map."
# define COLUMN_ERROR_MESSAGE "Error: Inconsistent number of \
columns in map rows."

// # define WIDTH 900
// # define HEIGHT 600
# define WIDTH 1920
# define HEIGHT 1080

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
}	t_vector;

typedef struct s_map
{
	t_vector		*base;
	t_vector		*fixed;
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
	double		**z_buf;
	void		*mlx;
	void		*win;
	t_data		img;
	t_vector	*pre_mouse;
	t_vector	*rotate_center;
	t_vector	*tran_center;
}			t_vars;

t_map			***get_map(int fd, double y);

t_vector		*create_vector4(double x, double y, double z, double w);
bool			get_center(t_map ***map, t_vector *center_pos);
double			rad(double deg);

bool			trans(t_map ***map, t_vector *vector, bool is_free, bool rev);
bool			scale(t_map ***map, double ratio, bool rev);
bool			rotate(t_map ***map, t_vector *vector, bool is_free, bool rev);

void			my_mlx_main(t_map ***map);
int				draw(t_vars *vars);
unsigned int	get_color(t_map *p0, t_vector tmp, t_map *p1);

int				mouse_move(int x, int y, t_vars *vars);
int				mouse_down(int key, int x, int y, t_vars *vars);
int				mouse_up(int key, int x, int y, t_vars *vars);

void			*free_map3(t_map ***map, int free_index, char *error_message);
void			*free_map2(t_map **map, char *error_message);
void			*free_map(t_map *map, char *error_message);

void			*return_error_null(char *error_message);
void			*return_error_bool(char *error_message);

#endif
