/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchevald <pchevald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/29 16:03:06 by pchevald          #+#    #+#             */
/*   Updated: 2014/12/02 23:57:04 by pchevald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <mlx.h>
# include <errno.h>
# define WIN_W 1600
# define WIN_H 1000
# define P_CTE 2
# define UP_COLOR 0xFF0000
# define MID_COLOR 0xFF6600
# define DOWN_COLOR 0xFFFFFF

typedef struct	s_coord
{
	int				x;
	int				y;
	int				z;
	int				x2;
	int				y2;
	struct s_coord	*next;
}				t_coord;

typedef struct	s_env
{
	void	*mlx;
	void	*win;
	t_coord	*map;
	double	angle;
	int		scale;
	int		x;
	int		y;
	int		xmax;
	int		ymax;
}				t_env;

// hook_callbacks.c
int				expose_hook(t_env *e);
int				key_hook(int keycode, t_env *e);
int				mouse_hook(int button, int x, int y, t_env *e);
// map.c
t_coord			*create_map(t_coord **list, int ac, char **av, t_env *e);
void			add_perspective(t_env *e);
// print.c
void			print_grid(t_env *e);
// list_tools.c
void			lstcoord(t_coord **list, t_env *e);
void			lstcoord2(t_coord **list, t_env *e);
void			lstcoord3(t_coord **list, t_env *e);
t_coord			*lstnew(int x, int y, int z, t_env *e);
int				lstsize(t_coord *list);
t_coord			*lstlast(t_coord *list);
t_coord			*lstprevup(t_coord *beginlist, t_coord *list);
// draw_line.c
void			draw_line1(t_env *e, t_coord *pt1, t_coord *pt2);
void			draw_line2(t_env *e, t_coord *pt1, t_coord *pt2);
void			draw_line(t_env *e, t_coord *pt1, t_coord *pt2);

#endif
