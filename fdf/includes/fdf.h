/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 12:03:27 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/05/30 15:48:42 by hkoizumi         ###   ########.fr       */
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

typedef struct s_data
{
	int				x;
	int				y;
	int				z;
	unsigned int	color;
}	t_data;

t_data	***get_map_data(char	*map_file);
void	*free_data(t_data ***data);

#endif
