/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduperon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 15:02:32 by qduperon          #+#    #+#             */
/*   Updated: 2016/12/23 15:02:34 by qduperon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

double		ft_sphere(t_obj *obj, t_env *e)
{
	double	a;
	double	b;
	double	c;
	double	discr;
	t_vec	dist;

	dist = sub_vect(e->cam_pos, obj->pos);
	a = dot_vect(e->ray_dir, e->ray_dir);
	b = 2 * dot_vect(e->ray_dir, dist);
	c = dot_vect(dist, dist) - (obj->size * obj->size);
	discr = b * b - 4 * a * c;
	c = ((-b + sqrtf(discr)) / (2 * a));
	discr = ((-b - sqrtf(discr)) / (2 * a));
	if (discr > c)
		discr = c;
	if (discr < 0)
		return (-1);
	return (discr);
}

double		ft_plan(t_obj *obj, t_env *env)
{
	double	t;
	t_obj	*node;

	node = obj;
	t = ((dot_vect(node->rot, node->pos) - dot_vect(node->rot, env->cam_pos)) \
			/ dot_vect(node->rot, env->ray_dir));
	if (t < 0)
		return (-1);
	return (t);
}

double		ft_cylindre(t_obj *node, t_env *e)
{
	double	disc;
	double	a;
	double	b;
	double	c;
	t_vec	dist;

	dist = sub_vect(e->cam_pos, node->pos);
	node->rot = norm_vect(node->rot);
	a = dot_vect(e->ray_dir, e->ray_dir) - \
		pow(dot_vect(e->ray_dir, node->rot), 2);
	b = 2 * (dot_vect(e->ray_dir, dist) - dot_vect(e->ray_dir, node->rot) * \
			dot_vect(dist, node->rot));
	c = dot_vect(dist, dist) - powf(dot_vect(dist, node->rot), 2) - \
		pow(node->size, 2);
	disc = b * b - 4 * a * c;
	if (disc < 0)
		return (-1);
	c = (-b + sqrtf(disc)) / (2 * a);
	disc = (-b - sqrtf(disc)) / (2 * a);
	if (c > EPSI && c < disc)
		return (c);
	else
		return (disc);
}

double		ft_cone(t_obj *node, t_env *e)
{
	double	disc;
	double	a;
	double	b;
	double	c;
	t_vec	dist;

	dist = sub_vect(e->cam_pos, node->pos);
	node->rot = norm_vect(node->rot);
	a = dot_vect(e->ray_dir, e->ray_dir) - (1 + powf(tanf(\
		deg_to_rad(node->size)), 2)) * pow(dot_vect(e->ray_dir, node->rot), 2);
	b = 2 * (dot_vect(e->ray_dir, dist) - \
			(1 + powf(tanf(deg_to_rad(node->size)), 2)) * \
			dot_vect(e->ray_dir, node->rot) * dot_vect(dist, node->rot));
	c = dot_vect(dist, dist) - (1 + powf(tanf(deg_to_rad(node->size)), 2)) * \
		pow(dot_vect(dist, node->rot), 2);
	disc = b * b - 4 * a * c;
	if (disc < 0)
		return (-1);
	c = (-b + sqrtf(disc)) / (2 * a);
	disc = (-b - sqrtf(disc)) / (2 * a);
	if (c > EPSI && c < disc)
		return (c);
	else
		return (disc);
}

t_obj		*ft_intersection(t_env *e, t_obj *node)
{
	t_obj	*tmp;
	t_obj	lum;

	e->dist = 0.0;
	lum.pos = e->spots->pos;
	lum.size = e->spots->size;
	lum.type = 5;
	lum.col = e->spots->col;
	tmp = NULL;
	e->d = 20000.0;
	return (inter_loop(node, e, tmp, lum));
}
