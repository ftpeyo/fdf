/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchevald <pchevald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 23:19:41 by pchevald          #+#    #+#             */
/*   Updated: 2014/11/08 01:46:49 by pchevald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_iswhitespace(char c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	return (0);
}

char		*ft_strtrim(char const *s)
{
	char	*ret;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (s == NULL)
		return (NULL);
	if (!(ret = ft_strnew(ft_strlen(s) + 1)))
		return (NULL);
	while (ft_iswhitespace(s[i]))
		i++;
	while (s[i])
	{
		ret[j] = s[i];
		i++;
		j++;
	}
	ret[j--] = '\0';
	while (ft_iswhitespace(ret[j]))
		ret[j--] = '\0';
	return (ret);
}
