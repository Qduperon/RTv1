/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plan.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduperon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/11 16:58:10 by qduperon          #+#    #+#             */
/*   Updated: 2016/10/11 17:43:54 by qduperon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RTv1.h"

t_plan			*ft_new_plan(double dis, t_color *color, t_pos *pos)
{
	t_plan	*p;

	if (!(p = (t_plan *)malloc(sizeof(t_plan))))
		return (NULL);
	p->dis = dis;
	p->color = color;
	p->pos = pos;
	return (c);
}

void			ft_add_plan(t_plan *start, t_plan *new)
{
	while (start->next)
		start = start->next;
	start->next = new;
}

t_plan			*ft_get_plan(int fd)
{
	char	*line;
	double	dis;
	int		ret;
	t_color	*color;
	t_pos	*pos;

	while ((ret = get_next_line(fd, &line)) > 0 && ft_strcmp(line, "-------"))
	{
		if (!ft_strcmp("pos:", line))
			pos = ft_vector(fd);
		if (!ft_strcmp("dis:", line))
		{
			ret = get_next_line(fd, &line);
			dis = ft_atodouble(&line);
		}
		if (!ft_strcmp("color:", line))
			color = ft_color(fd);
	}
	if (ret == -1)
		exit(-1);
	return (ft_new_plan(dis, color, pos));
}

t_plan			*ft_get_plans(int fd)
{
	char	*line;
	int		ret;
	t_plan	*p;

	p = NULL;
	while ((ret = get_next_line(fd, &line)) > 0 && ft_strcmp("-------", line))
	{
		if (!ft_strcmp("new:", line))
		{
			if (p == NULL)
				c = ft_get_plan(fd);
			else
				ft_add_plan(p, ft_get_plan(fd));
		}
		if (ret == -1)
			exit(-1);
	}
	return (p);
}