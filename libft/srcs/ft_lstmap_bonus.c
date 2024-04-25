/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 12:52:50 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/04/19 16:44:37 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*return_lst;
	t_list	*new_node;

	if (!lst || !f || !del)
		return (NULL);
	return_lst = NULL;
	while (lst)
	{
		new_node = ft_lstnew(f(lst->content));
		ft_lstadd_back(&return_lst, new_node);
		if (!new_node)
		{
			ft_lstclear (&return_lst, del);
			return (NULL);
		}
		lst = lst->next;
	}
	return (return_lst);
}
