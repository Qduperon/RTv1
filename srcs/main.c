/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduperon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 15:02:52 by qduperon          #+#    #+#             */
/*   Updated: 2016/12/23 15:02:56 by qduperon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

int				ft_error(char *str, int ex)
{
	ft_putendl(str);
	exit(ex);
}

void			display(t_env *e)
{
	t_obj		*node;
	char		*str;

	str = NULL;
	node = e->obj;
	while (node->type != 1)
		node = node->next;
	mlx_string_put(e->mlx, e->win, 5, 15, RED, "light x: ");
	mlx_string_put(e->mlx, e->win, 5, 30, RED, "light y: ");
	mlx_string_put(e->mlx, e->win, 5, 45, RED, "light z: ");
	mlx_string_put(e->mlx, e->win, 95, 15, RED, str = ft_itoa(e->spots->pos.x));
	free(str);
	mlx_string_put(e->mlx, e->win, 95, 30, RED, str = ft_itoa(e->spots->pos.y));
	free(str);
	mlx_string_put(e->mlx, e->win, 95, 45, RED, str = ft_itoa(e->spots->pos.z));
	free(str);
	mlx_string_put(e->mlx, e->win, 5, 175, RED, "cam_pos z: ");
	mlx_string_put(e->mlx, e->win, 105, 175, RED, str = ft_itoa(e->cam_pos.z));
	free(str);
}

static t_env	*init_env(char *map)
{
	t_env		*e;

	if (!(e = (t_env *)malloc(sizeof(t_env))))
		return (NULL);
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, W, H, "rtv1");
	e->img = (t_img *)malloc(sizeof(t_img));
	e->img->img = mlx_new_image(e->mlx, W, H);
	e->img->data = mlx_get_data_addr(e->img->img, &e->img->bpp, \
			&e->img->s_line, &e->img->endian);
	e->obj = NULL;
	e->spots = NULL;
	e->dist = 0;
	ft_init_scene(map, e);
	return (e);
}

int				main(int ac, char **av)
{
	t_env		*env;
	int			fd;

	fd = 0;
	if (ac != 2 || (fd = open(av[1], O_RDONLY) == -1) || (ft_strcmp(av[1], \
		"scene/") < 0))
		ft_error("Usage : ./rtv1 scene_file (ex: ./rtv1 scene/demo.1)", 0);
	if (close(fd) == -1)
		ft_error("Usage : ./rtv1 scene_file (ex: ./rtv1 scene/demo.1)", 0);
	else if ((env = init_env(av[1])) != NULL)
	{
		draw(env);
		mlx_hook(env->win, 2, 1L << 0, ft_keyhook, env);
		mlx_hook(env->win, 17, (1L << 17), ft_red_cross, 0);
		mlx_loop(env->mlx);
	}
	return (0);
}
