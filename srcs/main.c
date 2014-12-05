/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchevald <pchevald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/29 16:02:04 by pchevald          #+#    #+#             */
/*   Updated: 2014/12/02 23:56:04 by pchevald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

int		main(int ac, char **av)
{
	t_env	e;
	t_coord	*map;

	map = NULL;
	e.scale = 20;
	e.x = e.scale * 20;
	e.y = e.scale * 15;
	e.xmax = 0;
	e.ymax = 0;
	e.angle = 0.60;
	if (!(e.mlx = mlx_init())
		|| !(e.win = mlx_new_window(e.mlx, WIN_W, WIN_H, "42 FdF"))
		|| !(e.map = create_map(&map, ac, av, &e)))
		return (0);
	mlx_key_hook(e.win, key_hook, &e);
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_mouse_hook(e.win, mouse_hook, &e);
	mlx_loop(e.mlx);
	return (0);
}
