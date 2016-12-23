/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduperon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 15:04:55 by qduperon          #+#    #+#             */
/*   Updated: 2016/12/23 15:04:57 by qduperon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rtv1.h"

void	ft_add_obj(t_obj *start, t_obj *new)
{
	while (start->next)
		start = start->next;
	start->next = new;
}

void	ft_add_spot(t_spot *start, t_spot *new)
{
	while (start->next)
		start = start->next;
	start->next = new;
}

void	ft_init_scene(char *scene, t_env *env)
{
	char	**file;
	int		i;

	i = 0;
	file = NULL;
	file = ft_files(scene, file);
	while (!ft_strstr(file[i], "END"))
	{
		if (ft_strstr(file[i], "camera:"))
			ft_get_camera(file, env, i);
		if (ft_strstr(file[i], "spot:"))
			env->spots = ft_get_spots(file, env, i);
		if (ft_strstr(file[i], "cone:"))
			env->obj = ft_get_cones(file, env, i);
		if (ft_strstr(file[i], "cylindre:"))
			env->obj = ft_get_cylinds(file, env, i);
		if (ft_strstr(file[i], "plan:"))
			env->obj = ft_get_plans(file, env, i);
		if (ft_strstr(file[i], "sphere:"))
			env->obj = ft_get_spheres(file, env, i);
		i++;
	}
	ft_free_tab(file, i);
	free(file);
}
