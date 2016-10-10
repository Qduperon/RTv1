/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduperon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 16:08:08 by qduperon          #+#    #+#             */
/*   Updated: 2016/10/10 15:50:03 by qduperon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RTv1.h"

int		main(int ac, char **av)
{
	t_env	env;
	t_img	img;

	if (ac == 2)
		ft_RTv1(av[1]);
	else
		ft_error();
	//if (!(env.mlx = mlx_init()))
	//	return (-1);
	//img.img = mlx_new_image(env.mlx, HEIGHT, WIDTH);
	//img.data = mlx_get_data_addr(img.img, &img.bpp, &img.sl, &img.endian);
	//env.img = &img;
	//env.win = mlx_new_window(env.mlx, HEIGHT, WIDTH, "RTv1");
	env.cam = ft_init_cam();
	ft_parser(av[1], &env);
	ft_putnbr((int)env.cam->pos.x);
	//mlx_loop(env.mlx);
	return (0);
}
