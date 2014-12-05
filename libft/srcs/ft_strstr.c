/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchevald <pchevald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 21:54:08 by pchevald          #+#    #+#             */
/*   Updated: 2014/11/11 00:10:49 by pchevald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (ft_strlen(s2) == 0)
		return ((char *)s1);
	while (s1[i] && s2[j])
	{
		if (s1[i] == s2[j])
			j++;
		else
			j = 0;
		i++;
	}
	if (j == ft_strlen(s2))
		return ((char *)s1 + (i - j));
	return (NULL);
}
