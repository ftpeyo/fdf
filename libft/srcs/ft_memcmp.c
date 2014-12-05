/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchevald <pchevald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 22:41:36 by pchevald          #+#    #+#             */
/*   Updated: 2014/11/08 01:28:31 by pchevald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*ts1;
	unsigned char	*ts2;

	i = 0;
	ts1 = (unsigned char *)s1;
	ts2 = (unsigned char *)s2;
	if (n)
	{
		while (ts1[i] && ts2[i] && i < n && ts1[i] == ts2[i])
			i++;
		if (i == n)
			return (0);
		if (ts1[i] != ts2[i])
			return ((int)(ts1[i] - ts2[i]));
	}
	return (0);
}
