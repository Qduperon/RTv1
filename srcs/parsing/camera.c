/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduperon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 15:03:26 by qduperon          #+#    #+#             */
/*   Updated: 2016/12/23 15:03:28 by qduperon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rtv1.h"

void		ft_get_camera(char **line, t_env *env, int i)
{
	while (!ft_strstr(line[i], "-------"))
	{
		if (ft_strstr(line[i], "pos:"))
			env->cam_pos = ft_vector(line[i + 1]);
		if (ft_strstr(line[i], "dir:"))
			env->cam_dir = ft_vector(line[i + 1]);
		i++;
	}
}
