/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchevald <pchevald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 07:19:37 by pchevald          #+#    #+#             */
/*   Updated: 2014/11/29 13:50:52 by pchevald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 256

int				get_next_line(int const fd, char **line);

typedef struct	s_line
{
	int				fd;
	int				end;
	char			*rest;
	struct s_line	*next;
}				t_line;

#endif
