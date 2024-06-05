/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_vector4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 14:25:28 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/06/03 15:04:27 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_vector4	*create_vector4(double x, double y, double z, double w)
{
	t_vector4	*vector4;

	vector4 = (t_vector4 *)ft_calloc(1, sizeof(t_vector4));
	if (!vector4)
		return (NULL);
	*vector4 = (t_vector4){x, y, z, w};
	return (vector4);
}
