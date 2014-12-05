/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchevald <pchevald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/30 22:02:39 by pchevald          #+#    #+#             */
/*   Updated: 2014/12/01 01:44:26 by pchevald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_line1(t_env *e, t_coord *pt1, t_coord *pt2)
{
	int	x;
	int	y;

	x = pt1->x2;
	while (x < pt2->x2)
	{
		y = pt1->y2 + ((pt2->y2 - pt1->y2) * (x - pt1->x2))/(pt2->x2 - pt1->x2);
		if (pt1->z > 0 && pt2->z > 0)
			mlx_pixel_put(e->mlx, e->win, x, y, UP_COLOR);
		else if (pt1->z > 0 || pt2->z > 0)
			mlx_pixel_put(e->mlx, e->win, x, y, MID_COLOR);
		else
			mlx_pixel_put(e->mlx, e->win, x, y, DOWN_COLOR);
		x++;
	}
}

void	draw_line2(t_env *e, t_coord *pt1, t_coord *pt2)
{
	int	x;
	int	y;

	y = pt1->y2;
	while (y < pt2->y2)
	{
		x = pt1->x2 + ((pt2->x2 - pt1->x2) * (y - pt1->y2))/(pt2->y2 - pt1->y2);
		if (pt1->z > 0 && pt2->z > 0)
			mlx_pixel_put(e->mlx, e->win, x, y, UP_COLOR);
		else if (pt1->z > 0 || pt2->z > 0)
			mlx_pixel_put(e->mlx, e->win, x, y, MID_COLOR);
		else
			mlx_pixel_put(e->mlx, e->win, x, y, DOWN_COLOR);
		y++;
	}
}

#include "libft.h"

void	draw_line(t_env *e, t_coord *pt1, t_coord *pt2)
{
	int	x;
	int	y;

	x = pt1->x2 - pt2->x2;
	y = pt1->y2 - pt2->y2;
	if (x < 0)
		x *= -1;
	if (y < 0)
		y *= -1;
	if (x > y)
	{
		if (pt1->x2 <= pt2->x2)
			draw_line1(e, pt1, pt2);
		else
			draw_line1(e, pt2, pt1);
	}
	else
	{
		if (pt1->y2 < pt2->y2)
			draw_line2(e, pt1, pt2);
		else
			draw_line2(e, pt2, pt1);
	}
}
