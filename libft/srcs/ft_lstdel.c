/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchevald <pchevald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 03:45:05 by pchevald          #+#    #+#             */
/*   Updated: 2014/11/08 06:34:36 by pchevald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	if (*alst != NULL)
	{
		while (*alst)
		{
			(*del)((*alst)->content, (*alst)->content_size);
			(*alst)->content_size = 0;
			*alst = (*alst)->next;
		}
		free(*alst);
		*alst = NULL;
	}
}
