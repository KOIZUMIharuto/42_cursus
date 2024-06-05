/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 12:03:27 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/06/03 15:38:11 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include <errno.h>
# include <stdio.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>

# include <stdio.h>

# include "../minilibx_macos/mlx.h"
# include "../libft/includes/libft.h"

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
	t_vector4		*origin;
	t_vector4		*fixed;
	unsigned int	color;
}	t_data;

t_data		***get_map_data(char	*map_file);
t_vector4	*create_vector4(double x, double y, double z, double w);
void		*free_data(t_data ***data);

#endif
