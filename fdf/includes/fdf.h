/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxx <xxxx@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 12:03:27 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/06/06 23:02:39 by xxxx             ###   ########.fr       */
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
# define ATODBL_ERROR_MESSAGE "Error: Invalid value in map."
# define COLUMN_ERROR_MESSAGE "Error: Invalid column count."


# define WIDTH 1200
# define HIGHT 800

# define UPPER_HEX_LIST "0123456789ABCDEF"
# define LOWER_HEX_LIST "0123456789abcdef"

typedef struct s_vector4
{
	double			x;
	double			y;
	double			z;
	double			w;
}	t_vector4;

typedef struct s_data
{
	t_vector4		*base;
	t_vector4		*fixed;
	unsigned int	color;
}	t_data;

t_data		***get_map(char	*map_file);
t_data		***recursive_gnl(int fd, double y);

bool		get_center(t_data ***data, t_vector4 *center_pos);
double		rad(double deg);

bool		trans(t_data ***data, t_vector4 *vector, bool is_free, bool rev);
bool		scale(t_data ***data, t_vector4 *vector, bool is_free, bool rev);
bool		rotate(t_data ***data, t_vector4 *vector, bool is_free, bool rev);

t_vector4	*create_vector4(double x, double y, double z, double w);
t_vector4	*add_sub_vector4(t_vector4 *vec_1, t_vector4 *vec_2, bool is_add);

void		*free_data3(t_data ***data, int free_index);
void		*free_data2(t_data **data);
void		*free_data(t_data *data);

void		*return_error_null(char *error_message);

#endif
