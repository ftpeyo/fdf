/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_callbacks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchevald <pchevald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/29 16:31:53 by pchevald          #+#    #+#             */
/*   Updated: 2014/12/02 23:06:42 by pchevald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h" // tests
#include <stdlib.h> // exit();
#include <stdio.h> // printf();

int	expose_hook(t_env *e)
{
	add_perspective(e);
	mlx_clear_window(e->mlx, e->win);
	print_grid(e);
	return (0);
}

int	key_hook(int keycode, t_env *e)
{
	(void)e;
	if (keycode == 65307)
		exit(EXIT_SUCCESS);
	if (keycode == 65362)
		e->y -= e->scale;
	if (keycode == 65364)
		e->y += e->scale;
	if (keycode == 65361)
		e->x -= e->scale;
	if (keycode == 65363)
		e->x += e->scale;
	if (keycode == 65451)
		if (e->scale < 50)
			e->scale += 1;
	if (keycode == 65453)
		if (e->scale > 1)
			e->scale -= 1;
	if (keycode == 65460)
		if (e->angle < 6.3)
			e->angle += 0.1;
	if (keycode == 65462)
		if (e->angle > -3.15)
			e->angle -= 0.1;
	printf("e->angle : %f\n", e->angle);
	expose_hook(e);
	return (0);
}

int	mouse_hook(int button, int x, int y, t_env *e)
{
	(void)e;
	printf("Mouse : %d (%d, %d)\n", button, x, y);
	return (0);
}
