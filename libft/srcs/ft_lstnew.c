/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchevald <pchevald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 01:56:11 by pchevald          #+#    #+#             */
/*   Updated: 2014/11/08 06:33:09 by pchevald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_init_tlist(t_list **lst)
{
	if (!(*lst = (t_list *)malloc(sizeof(t_list))))
		return (0);
	if (!((*lst)->content = (void *)malloc(1)))
		return (0);
	if (!((*lst)->next = (t_list *)malloc(sizeof(t_list))))
		return (0);
	return (1);
}

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*newlink;

	newlink = NULL;
	if (!ft_init_tlist(&newlink))
		return (NULL);
	if (content == NULL)
	{
		newlink->content = NULL;
		newlink->content_size = 0;
	}
	else
	{
		ft_memcpy(newlink->content, content, content_size);
		newlink->content_size = content_size;
	}
	newlink->next = NULL;
	return (newlink);
}
