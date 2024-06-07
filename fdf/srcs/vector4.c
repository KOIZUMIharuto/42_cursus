/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxx <xxxx@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 14:25:28 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/06/07 11:50:40 by xxxx             ###   ########.fr       */
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
