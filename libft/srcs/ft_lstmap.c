/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchevald <pchevald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 04:08:01 by pchevald          #+#    #+#             */
/*   Updated: 2014/11/08 06:27:18 by pchevald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*newlist;
	t_list	*begin;
	t_list	*newlist_prev;

	newlist = NULL;
	begin = NULL;
	newlist_prev = NULL;
	while (lst)
	{
		newlist = (*f)(lst);
		if (newlist_prev != NULL)
			newlist_prev->next = newlist;
		else
			begin = newlist;
		newlist_prev = newlist;
		lst = lst->next;
	}
	return (begin);
}
