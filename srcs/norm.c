/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduperon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 15:01:51 by qduperon          #+#    #+#             */
/*   Updated: 2016/12/23 15:01:53 by qduperon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

t_vec		normale(t_obj *obj, t_env *env, t_vec cam)
{
	t_vec	result;
	t_vec	tmp;
	t_vec	temp;

	if (obj->type == 0)
	{
		result = obj->rot;
		result = inv(result, env, obj);
	}
	else
	{
		if (obj->type == 1)
			result = sub_vect(cam, obj->pos);
		else
		{
			temp = scale_vect(obj->rot, dot_vect(env->ray_dir, obj->rot) * \
				env->d + dot_vect(sub_vect(env->cam_pos, obj->pos), obj->rot));
			if (obj->type == 2)
				temp = scale_vect(temp, \
						(1 + powf(tanf(deg_to_rad(obj->size)), 2)));
			tmp = sub_vect(cam, obj->pos);
			result = sub_vect(tmp, temp);
		}
	}
	return (norm_vect(result));
}
