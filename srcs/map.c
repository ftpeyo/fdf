/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchevald <pchevald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/29 20:40:19 by pchevald          #+#    #+#             */
/*   Updated: 2014/12/02 23:46:51 by pchevald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "fdf.h"
#include "libft.h"
#include "get_next_line.h"

static int	check_params(int ac, char **av, int *fd)
{
	if (ac == 1)
	{
		ft_putstr_fd("usage : ", 2);
		ft_putstr_fd(av[0], 2);
		ft_putstr_fd(" file1\n", 2);
		return (0);
	}
	if ((*fd = open(av[1], O_RDONLY)) < 3)
	{
		strerror(errno);
		return (0);
	}
	return (1);
}

static t_coord	**lst_map_conversion(t_coord **list, char *line, t_env *e)
{
	static int	y = 0;
	int			i;
	int			x;
	int			z;
	t_coord		*cursor;

	i = 0;
	x = 0;
	while (line[i])
	{
		while (line[i] == ' ')
			i++;
		z = ft_atoi(&line[i]);
		if (*list)
		{
			cursor = lstlast(*list);
			cursor->next = lstnew(x, y, z, e);
		}
		else
			*list = lstnew(x, y, z, e);
		i += ft_intlen(z);
		x++;
	}
	y++;
	return (list);
}

t_coord		*create_map(t_coord **list, int ac, char **av, t_env *e)
{
	int		fd;
	char	*line;

	line = NULL;
	fd = 0;
	if (!(check_params(ac, av, &fd)))
		return (NULL);
	while (get_next_line(fd, &line))
	{
		list = lst_map_conversion(list, line, e);
		free(line);
	}
	close(fd);
	return (*list);
}

void		add_perspective(t_env *e)
{
	t_coord	*cursor;

	cursor = e->map;
	while (cursor)
	{
		lstcoord(&cursor, e);
		lstcoord2(&cursor, e);
		lstcoord3(&cursor, e);
		cursor = cursor->next;
	}
}
