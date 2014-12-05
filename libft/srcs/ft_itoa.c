/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchevald <pchevald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 19:51:59 by pchevald          #+#    #+#             */
/*   Updated: 2014/11/29 13:52:03 by pchevald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbsize(int n)
{
	int	ret;

	ret = 0;
	if (n <= 0)
	{
		ret++;
		n *= -1;
	}
	while (n > 0)
	{
		n /= 10;
		ret++;
	}
	return (ret);
}

char		*ft_itoa(int n)
{
	char	*ret;
	int		size;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	size = ft_nbsize(n);
	if (!(ret = ft_strnew(size + 1)))
		return (NULL);
	ret[size--] = '\0';
	if (n == 0)
		ret[0] = '0';
	else if (n < 0)
	{
		ret[0] = '-';
		n *= -1;
	}
	while (n > 0)
	{
		ret[size] = n % 10 + 48;
		n /= 10;
		size--;
	}
	return (ret);
}
