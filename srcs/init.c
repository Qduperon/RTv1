/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduperon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/07 18:52:03 by qduperon          #+#    #+#             */
/*   Updated: 2016/10/11 15:31:41 by qduperon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RTv1.h"

t_cam		*ft_new_camera(t_pos pos, t_pos dir)
{
	t_cam	*c;

	if (!(c = (t_cam *)malloc(sizeof(t_cam))))
		return (NULL);
	c->pos = pos;
	c->dir = dir;
	return (c);
}

t_scene		*ft_get_scene(void)
{
	static t_scene *s;

	s = NULL;
	if (s == NULL)
	{
		if (!(s = (t_scene *)malloc(sizeof(t_scene))))
			return (NULL);
		s->cam = NULL;
		s->cone = NULL;
		s->cylind = NULL;
		s->plan = NULL;
		s->sphere = NULL;
		s->spot = NULL;
	}
	return (s);
}

void		ft_init_scene(char *scene)
{
	char	*line;
	int		fd;
	int		ret;
	t_scene	*s;

	if ((fd = open(scene, O_RDONLY) == -1))
		exit(-1);
	s = ft_get_scene();
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if (!ft_strcmp("camera:", line))
			s->cam = ft_get_camera(fd);	
		if (!ft_strcmp("cone:", line))
			s->cone = ft_get_cones(fd);
		if (!ft_strcmp("cylindre:", line))
			s->cylind = ft_get_cylinds(fd);
		if (!ft_strcmp("plan:", line))
			s->plan = ft_get_plans(fd);
		if (!ft_strcmp("sphere:", line))
			s->sphere = ft_get_spheres(fd);
		if (!ft_strcmp("spot:", line))
			s_>spot = ft_get_spots(fd);
	}
	if (ret == -1)
		exit (-1);
}
