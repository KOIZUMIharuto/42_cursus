/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxx <xxxx@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 14:25:28 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/06/06 23:04:27 by xxxx             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_vector4	*create_vector4(double x, double y, double z, double w)
{
	t_vector4	*vector4;

	vector4 = (t_vector4 *)ft_calloc(1, sizeof(t_vector4));
	if (!vector4)
		return (return_error_null(strerror(errno)));
	*vector4 = (t_vector4){x, y, z, w};
	return (vector4);
}

t_vector4	*add_sub_vector4(t_vector4 *vec_1, t_vector4 *vec_2, bool is_add)
{
	t_vector4	*result;

	if (!vec_1 || !vec_2)
		return (NULL);
	result = create_vector4(0, 0, 0, 0);
	if (!result)
		return (NULL);
	result->x = vec_1->x + (2 * (int)is_add - 1) * vec_2->x;
	result->y = vec_1->y + (2 * (int)is_add - 1) * vec_2->y;
	result->z = vec_1->z + (2 * (int)is_add - 1) * vec_2->z;
	return (result);
}