/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 11:56:03 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/02/12 12:51:26 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		content_count;
	t_list	*lst_tmp;

	content_count = 0;
	lst_tmp = lst;
	while (lst_tmp)
	{
		content_count++;
		lst_tmp = lst_tmp->next;
	}
	return (content_count);
}
