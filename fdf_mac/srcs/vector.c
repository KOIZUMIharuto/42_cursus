/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 14:25:28 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/06/10 14:42:45 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_vector	*create_vector4(double x, double y, double z, double w)
{
	t_vector	*vector4;

	vector4 = (t_vector *)ft_calloc(1, sizeof(t_vector));
	if (!vector4)
		return (return_error_null(strerror(errno)));
	*vector4 = (t_vector){x, y, z, w};
	return (vector4);
}
