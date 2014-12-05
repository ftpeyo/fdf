/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchevald <pchevald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/23 03:47:40 by pchevald          #+#    #+#             */
/*   Updated: 2014/11/29 14:40:29 by pchevald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "libft.h"
#include "get_next_line.h"

static void		clean_lst(t_line **beginlist)
{
	t_line	*cursorlist;
	t_line	*previouslist;

	cursorlist = *beginlist;
	while (cursorlist)
	{
		if (cursorlist->end == 1)
		{
			free(cursorlist->rest);
			if (cursorlist == *beginlist)
				*beginlist = cursorlist->next;
			else if (!cursorlist->next)
				previouslist->next = NULL;
			else
				previouslist->next = cursorlist->next;
			free(cursorlist);
		}
		previouslist = cursorlist;
		cursorlist = cursorlist->next;
	}
}

static t_line	*find_lst_fd(t_line **beginlist, int const fd)
{
	t_line			*cursorlist;
	t_line			*curentlist;

	cursorlist = *beginlist;
	curentlist = NULL;
	while (cursorlist)
	{
		if (cursorlist->fd == fd)
			curentlist = cursorlist;
		cursorlist = cursorlist->next;
	}
	if (!curentlist)
	{
		if (!(curentlist = (t_line *)malloc(sizeof(t_line)))
			|| !(curentlist->rest = ft_strnew(BUFF_SIZE)))
			return (NULL);
		curentlist->next = *beginlist;
		curentlist->fd = fd;
		curentlist->end = 0;
		*beginlist = curentlist;
	}
	return (curentlist);
}

static int		treatment(t_line *curentlist, char **buf, char **line)
{
	char	*n;

	n = 0;
	if ((n = ft_strchr(*buf, '\n')))
	{
		ft_strcpy(curentlist->rest, n + 1);
		if (!(*line = ft_strjoin(*line, ft_strsub(*buf, 0, n - *buf))))
			return (-1);
		ft_strdel(buf);
		return (1);
	}
	if (!(*line = ft_strjoin(*line, *buf)))
		return (-1);
	ft_bzero(*buf, BUFF_SIZE);
	return (0);
}

static int		createline(t_line *curentlist, char **line)
{
	char	*buf;
	int		ret;

	ret = 0;
	if (!(buf = ft_strnew(BUFF_SIZE)))
		return (-1);
	while ((ret = read(curentlist->fd, buf, BUFF_SIZE)))
		if ((ret = treatment(curentlist, &buf, line)))
			return (ret);
	ft_strdel(&buf);
	if (ret == 0)
	{
		curentlist->end = 1;
		return (1);
	}
	return (0);
}

int				get_next_line(int const fd, char **line)
{
	static t_line	*beginlist = NULL;
	t_line			*curentlist;
	int				ret;
	char			*buf;

	ret = 0;
	buf = 0;
	if (fd < 0 || !line || (!(curentlist = find_lst_fd(&beginlist, fd)))
		|| (!(*line = ft_strnew(1))) || BUFF_SIZE < 1)
		return (-1);
	if (curentlist->rest)
	{
		if (!(buf = ft_strnew(BUFF_SIZE)) || !ft_strcpy(buf, curentlist->rest))
			return (-1);
		if ((ret = treatment(curentlist, &buf, line)))
			return (ret);
		ft_strdel(&buf);
		ft_bzero(curentlist->rest, BUFF_SIZE);
	}
	while (curentlist->end == 0 && (ret = createline(curentlist, line)) == 0)
		;
	if (curentlist->end == 1)
		ret = 0;
	clean_lst(&beginlist);
	return (ret);
}
