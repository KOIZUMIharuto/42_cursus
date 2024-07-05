/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 12:03:27 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/07/05 18:06:12 by hkoizumi         ###   ########.fr       */
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

# define ARG_ERROR_MESSAGE "Missing required argument."
# define USAGE "Usage: ./fdf <path_to_map_file>"
# define EXTENSION_ERROR_MESSAGE "Invalid file extension."
# define EXTENTION "Required: .fdf file"
# define FILE_OPEN_ERROR_MESSAGE "Failed to open file."
# define ALTITUDE_ERROR_MESSAGE "Invalid altitude in map."
# define COLOR_ERROR_MESSAGE "Invalid color in map."
# define COLUMN_ERROR_MESSAGE "Inconsistent number of columns in map rows."
# define SCALE_ERROR_MESSAGE "Invalid scale ratio."
# define ZOOM_ERROR_MESSAGE "Zoom operation failed."
# define ROTATE_ERROR_MESSAGE "Rotation operation failed."
# define TRANSLATE_ERROR_MESSAGE "Translation operation failed."

# define WIDTH 1920
# define HEIGHT 1080

# define KEY_ESC 65307
# define KEY_SFT_L 65505

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
	bool		is_shift;
	t_vector	*pre_mouse;
	t_vector	*rotate_angle;
	t_vector	*tran_center;
	int			exit_status;
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
unsigned int	culc_color(t_map *p0, t_vector tmp, t_map *p1);
int				win_off(t_vars *vars);

int				key_pressed(int key_code, t_vars *vars);
int				key_released(int key_code, t_vars *vars);
int				mouse_move(int x, int y, t_vars *vars);
int				mouse_down(int key, int x, int y, t_vars *vars);
int				mouse_up(int key, int x, int y, t_vars *vars);

void			*free_map3(t_map ***map, int free_index, char *error_message);
void			*free_map2(t_map **map, int free_index, char *error_message);
void			*free_map(t_map *map, char *error_message);

void			*return_error_null(char *error_message);
void			*return_error_bool(char *error_message);

#endif
