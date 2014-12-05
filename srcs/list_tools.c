/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchevald <pchevald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/19 09:31:30 by pchevald          #+#    #+#             */
/*   Updated: 2014/12/03 00:06:57 by pchevald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <math.h>
#include "fdf.h"
#include "libft.h" // tests

void	lstcoord3(t_coord **list, t_env *e)
{
	(*list)->x2 -= ((*list)->y * e->scale / 4);
	(*list)->y2 += ((*list)->y * e->scale / 4);
}

void	lstcoord2(t_coord **list, t_env *e)
{
	(*list)->y2 -= e->scale / 2 * (*list)->y;
}

void	lstcoord(t_coord **list, t_env *e)
{
	int tmp1;
	int tmp2;
	(*list)->x2 = (*list)->x * e->scale - (e->scale * e->xmax / 2);
	(*list)->y2 = (*list)->y * e->scale - (e->scale * e->ymax / 2);
	tmp1 = (*list)->x2 * cos(e->angle) - (*list)->y2 * sin(e->angle);
	tmp2 = (*list)->x2 * sin(e->angle) + (*list)->y2 * cos(e->angle);
	(*list)->x2 = tmp1 + e->x + (e->scale * 10);
	(*list)->y2 = tmp2 + e->y + (e->scale * 10);
/*	(*list)->x2 = (10 - (*list)->x * e->scale);
	(*list)->y2 = (10 - (*list)->y * e->scale);
	tmp1 = (*list)->x2 * cos(e->angle)
		- (*list)->y2 * sin(e->angle);
	tmp2 = (*list)->x2 * sin(e->angle)
		+ (*list)->y2 * cos(e->angle);
	(*list)->x2 = tmp1 + e->x;
	(*list)->y2 = tmp2 + e->y;
*/	if ((*list)->z > 0)
	{
		(*list)->y2 -= e->scale * (*list)->z / 10;
	}
}

t_coord	*lstnew(int x, int y, int z, t_env *e)
{
	t_coord  *newcoord;

	newcoord = (t_coord *)malloc(sizeof(t_coord));
	newcoord->x = x;
	newcoord->y = y;
	newcoord->z = z;
	if (e->xmax < x)
		e->xmax = x;
	if (e->ymax < y)
		e->ymax = y;
	newcoord->next = NULL;
	return (newcoord);
}

int		lstsize(t_coord *list)
{
	int	ret;

	ret = 0;
	while (list)
	{
		ret++;
		list = list->next;
	}
	return (ret);
}

t_coord	*lstlast(t_coord *list)
{
	while (list->next)
		list = list->next;
	return (list);
}

t_coord	*lstprevup(t_coord *beginlist, t_coord *list)
{
	t_coord	*cursor;

	cursor = beginlist;
	while (cursor)
	{
		if (cursor->y == list->y - 1 && cursor->x == list->x)
			return (cursor);
		cursor = cursor->next;
	}
	return (NULL);
}
