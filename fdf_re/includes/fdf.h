/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 12:03:27 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/07/22 16:03:46 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <float.h>
# include <fcntl.h>
# include <errno.h>
# include <stdio.h>
# include <string.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>

# include "../minilibx-linux/mlx.h"
# include "../libft/includes/libft.h"

# define ARGUMENT_ERROR "Missing required argument."
# define USAGE "Usage: ./fdf <path_to_map_file>"
# define ARGUMENT_WARNING "Warning: Only the first argument is valid."
# define EXTENSION_ERROR "Invalid file extension."
# define EXTENTION_REQUIRED "Required: .fdf file"
# define FILE_OPEN_ERROR "Failed to open file."
# define ALTITUDE_ERROR "Invalid altitude in map."
# define COLOR_ERROR "Invalid color in map."
# define COLUMN_ERROR "Inconsistent number of columns in map rows."
# define SCALE_ERROR "Invalid scale ratio."
# define ZOOM_ERROR "Zoom operation failed."
# define ROTATE_ERROR "Rotation operation failed."
# define TRANSLATE_ERROR "Translation operation failed."

# define WIDTH 1920
# define HEIGHT 1080

# define KEY_R 114
# define KEY_ESC 65307
# define KEY_SFT_L 65505

# define ZOOM_RATIO 1.1

# define UPPER_HEX_LIST "0123456789ABCDEF"
# define LOWER_HEX_LIST "0123456789abcdef"

typedef struct s_vector_long
{
	int		x;
	int		y;
	double	z;
}	t_vect_int;

typedef struct s_end_dots
{
	t_vect_int	p0;
	t_vect_int	p1;
}	t_end_dots;

typedef struct s_vector
{
	double			x;
	double			y;
	double			z;
}	t_vector;

typedef struct s_dot
{
	t_vector		base;
	t_vector		fixed;
	unsigned int	color;
}	t_dot;

typedef struct s_xyc
{
	int		y;
	int		x;
	void	*content;
}	t_xyc;

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
	t_dot		**map;
	double		**z_buf;
	void		*mlx;
	void		*win;
	t_data		img;
	bool		on_mouse_down;
	bool		is_shift;
	t_vector	pre_mouse;
	t_vector	rotate_angle;
	t_vector	model_center;
	int			exit_status;
}			t_vars;

t_dot			**get_map(int fd, int y);

void			add_vector(t_vector *src, t_vector add, bool sign);
void			mult_vector(t_vector *src, double ratio, bool rev);
void			copy_vector(t_dot ***map, bool b_to_f);

bool			get_center(t_dot ***map, t_vector *center_pos);
double			rad(double deg);

bool			trans(t_dot **map, t_vector *vector, bool is_free, bool rev);
bool			scale(t_dot **map, double ratio, bool rev);
bool			rotate(t_dot **map, t_vector *vector, bool is_free, bool rev);

void			my_mlx_main(t_dot **map);
int				draw(t_vars *vars);
void			get_end_dot(t_vect_int *end_p, t_vector p0, t_vector p1);
void			draw_line(t_vars *vars, t_dot *p0, t_dot *p1);
unsigned int	culc_color(t_dot *p0, t_vect_int tmp, t_dot *p1);
int				win_off(t_vars *vars);

int				key_pressed(int key_code, t_vars *vars);
int				key_released(int key_code, t_vars *vars);
int				mouse_move(int x, int y, t_vars *vars);
int				mouse_down(int key, int x, int y, t_vars *vars);
int				mouse_up(int key, int x, int y, t_vars *vars);

void			*free_map3(t_dot **map, int free_index, char *error_message);
void			*free_map2(t_dot *map, int free_index, char *error_message);
void			*free_map(t_dot map, char *error_message);
void			free_xyc(void *xyc);

void			*return_error_null(char *error_message);
void			*return_error_bool(char *error_message);

#endif
