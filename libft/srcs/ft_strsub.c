/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchevald <pchevald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 23:19:41 by pchevald          #+#    #+#             */
/*   Updated: 2014/11/12 22:52:55 by pchevald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	char	*temp;
	size_t	i;

	temp = NULL;
	ret = NULL;
	i = 0;
	if (!s)
		return (NULL);
	if (!(ret = ft_strnew(len + 1)))
		return (NULL);
	temp = (char *)s + (char)start;
	while (i < len)
	{
		ret[i] = temp[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
