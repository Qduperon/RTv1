/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduperon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 17:41:09 by qduperon          #+#    #+#             */
/*   Updated: 2016/10/07 19:33:04 by qduperon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RTv1.h"

void		ft_error(void)
{
	ft_putendl("Wrong usage !");
	ft_putendl("Usage: ");
	ft_putendl("./RTv1 <scene>");
	exit(0);
}

void		ft_exit(char *s)
{
	ft_putendl(s);
	exit(0);
}

void		ft_free_error(t_env *env)
{
	free(env->cam);
	//ft_clear_obj(&env->obj);
	//ft_clear_spot(&env->spot);
	ft_putendl("Map Error");
	exit(0);
}

void		ft_free(t_env *env)
{
	free(env->cam);
	//ft_clear_obj(&env->obj);
	//ft_clear_spot(&env->spot);
	exit(0);
}
