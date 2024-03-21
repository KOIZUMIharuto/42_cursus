/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 12:18:11 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/03/21 13:42:54 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*now_lst_tmp;

	if (lst && del)
	{
		while (*lst)
		{
			now_lst_tmp = *lst;
			*lst = now_lst_tmp->next;
			ft_lstdelone(now_lst_tmp, del);
		}
	}
}
