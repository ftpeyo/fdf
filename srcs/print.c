/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchevald <pchevald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/29 16:02:04 by pchevald          #+#    #+#             */
/*   Updated: 2014/12/02 22:11:43 by pchevald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "fdf.h"

void	print_grid(t_env *e)
{
	t_coord	*cursor;
	t_coord	*cursorup;

	cursor = e->map;
	cursorup = NULL;
	while (cursor)
	{
		if (cursor->next && cursor->next->y == cursor->y)
			draw_line(e, cursor, cursor->next);
		if ((cursorup = lstprevup(e->map, cursor)))
			draw_line(e, cursor, cursorup);
		cursor = cursor->next;
	}
}
