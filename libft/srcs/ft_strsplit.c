/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchevald <pchevald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 18:11:20 by pchevald          #+#    #+#             */
/*   Updated: 2014/11/12 23:12:35 by pchevald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static size_t	ft_strlenc(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static size_t	wds(char const *s, char c)
{
	size_t	i;
	size_t	ret;

	i = 0;
	ret = 0;
	while (s[i])
	{
		if (s[i] == c)
			while (s[i] && s[i] == c)
				i++;
		if (s[i])
			ret++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (ret);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t		i;
	size_t		j;
	size_t		k;
	char		**ret;

	i = 0;
	j = 0;
	if (!s || !(ret = (char **)malloc(sizeof(char *) * (wds(s, c) + 1))))
		return (NULL);
	while (s[i])
	{
		k = 0;
		while (s[i] == c)
			i++;
		if (s[i])
		{
			if (!(ret[j] = ft_strnew(ft_strlenc(s + i, c) + 1)))
				return (NULL);
			while (s[i] && s[i] != c)
				ret[j][k++] = s[i++];
			ret[j++][k] = '\0';
		}
	}
	ret[j] = '\0';
	return (ret);
}
