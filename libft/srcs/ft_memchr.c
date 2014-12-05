/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchevald <pchevald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 17:06:18 by pchevald          #+#    #+#             */
/*   Updated: 2014/11/08 01:12:53 by pchevald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*temps;

	i = 0;
	if (s && n > 0)
	{
		temps = (unsigned char *)s;
		while (i < n)
		{
			if (temps[i] == (unsigned char)c)
				return ((void *)temps + i);
			i++;
		}
	}
	return (NULL);
}
