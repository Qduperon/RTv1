/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduperon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 16:11:01 by qduperon          #+#    #+#             */
/*   Updated: 2016/10/07 20:12:51 by qduperon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RTv1.h"

void	ft_camera(char *line, t_env *env)
{
	if (ft_strstr(line, "pos") == 0)
	{
		env->cam->pos.x = line[6];
		env->cam->pos.y = line[9];
		env->cam->pos.z = line[12];
	}
	if (ft_strstr(line, "dir") == 0)
	{
		env->cam->dir.x = line[6];
		env->cam->dir.y = line[9];
		env->cam->dir.z = line[12];
	}
}
/*
	while (line[i] == '-')
		i++;
	if (i == 7 && !line[i])
		return ;
	else
		ft_free_error(env);

}*/

void	ft_parser(char *av, t_env *env)
{
	int		fd;
	int		i;
	int		ret;
	char	*line;

	ft_putendl("coucou");
	if ((fd = open(av, O_RDONLY) < 0))
		ft_exit("file cannot be read");
	ft_putendl("BLOUBLOU");
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		ft_camera(line, env);
		//ft_check(line, &env);
	}
	if (ret == -1)
		exit(-1);
}
