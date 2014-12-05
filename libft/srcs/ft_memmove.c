/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchevald <pchevald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 01:50:38 by pchevald          #+#    #+#             */
/*   Updated: 2014/11/08 01:28:11 by pchevald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*tempdst;
	char	*tempsrc;

	tempdst = (char *)dst;
	tempsrc = (char *)src;
	if (dst < src)
	{
		while (len--)
			*tempdst++ = *tempsrc++;
	}
	else
	{
		tempdst += len;
		tempsrc += len;
		while (len--)
		{
			*--tempdst = *--tempsrc;
		}
	}
	return (dst);
}
