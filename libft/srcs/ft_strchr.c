/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchevald <pchevald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 20:57:39 by pchevald          #+#    #+#             */
/*   Updated: 2014/11/10 23:43:54 by pchevald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	*temps;

	i = 0;
	temps = (char *)s;
	while (temps[i] && temps[i] != (char)c)
		i++;
	if (i == ft_strlen(s) && temps[i] != (char)c)
		return (NULL);
	return (&temps[i]);
}
