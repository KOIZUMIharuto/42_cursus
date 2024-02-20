/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 12:52:50 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/02/13 19:23:33 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*return_lst;
	t_list	*return_lst_tmp;
	t_list	*lst_tmp;

	if (!lst || !f || !del)
		return (NULL);
	lst_tmp = lst;
	return_lst = NULL;
	while (lst_tmp)
	{
		return_lst_tmp = ft_lstnew(f(lst_tmp->content));
		if (!return_lst_tmp)
		{
			ft_lstclear (&return_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&return_lst, return_lst_tmp);
		lst_tmp = lst_tmp->next;
	}
	return (return_lst);
}
