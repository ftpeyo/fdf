/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchevald <pchevald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 17:39:15 by pchevald          #+#    #+#             */
/*   Updated: 2014/11/12 20:44:10 by pchevald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_strdel(char **ap)
{
	if (ap && *ap)
	{
		free(*ap);
		*ap = NULL;
	}
}
