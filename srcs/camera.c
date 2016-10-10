/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduperon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 16:57:26 by qduperon          #+#    #+#             */
/*   Updated: 2016/10/10 20:11:17 by qduperon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RTv1.h"

t_cam		*ft_get_camera(int fd)
{
	char		*line
	int 		ret
	t_cam		*c;
	t_vect		*look_at
	t_vect		*diff;

	c = ft_new_camera(NULL, NULL);
	while ((ret = get_next_line(fd, &line)) > 0 && ft_strcmp(line, "-------"))
	{
		if (!ft_strcmp("pos:", line))
			c->pos = ft_vector(fd);
		if (!ft_strcmp("dir:", line))
			look_at = ft_vector(fd);
	}
	diff = ft_new_vector(c->pos->x - look_at->x, \
			c->pos->y - look_at->y, c->pos->z - look_at->z);
	c->dir = ft_new_vector(NULL, NULL, NULL);
	c->dir = ft_norm(ft_neg(diff));
	ft_deleted_vect(look_at);
	ft_deleted_vect(diff);
	return (c);
}
