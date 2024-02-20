/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 12:46:42 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/02/13 19:23:55 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*lst_tmp;

	if (lst && f)
	{
		lst_tmp = lst;
		while (lst_tmp)
		{
			f(lst_tmp->content);
			lst_tmp = lst_tmp->next;
		}
	}
}
