/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 12:00:47 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/02/12 12:37:20 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*lst_tmp;

	if (!lst)
		return (NULL);
	lst_tmp = lst;
	while (lst_tmp->next)
		lst_tmp = lst_tmp->next;
	return (lst_tmp);
}
