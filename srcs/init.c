/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduperon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/07 18:52:03 by qduperon          #+#    #+#             */
/*   Updated: 2016/10/07 19:34:17 by qduperon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RTv1.h"

t_cam		*ft_init_cam(void)
{
	t_cam	*cam;

	cam = NULL;
	if (!(cam = (t_cam *)malloc(sizeof(t_cam))))
		return (0);
	cam->pos.x = 0;
	cam->pos.y = 0;
	cam->pos.z = 0;
	cam->dir.x = 0;
	cam->dir.y = 0;
	cam->dir.z = 0;
	return (cam);
}
