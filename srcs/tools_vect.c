/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_vect.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduperon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 19:58:20 by qduperon          #+#    #+#             */
/*   Updated: 2016/10/10 20:11:54 by qduperon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RTv1.h"

t_pos		*ft_neg(t_pos *v)
{
	v->x *= -1;
	v->y *= -1;
	v->z *= -1;
	return (v);
}

t_pos		*ft_norm(t_pos *v)
{
	double m;

	m = ft_magnitude(v);
	v->x /= m;
	v->y /= m;
	v->z /= m;
	return (v);
}

double		ft_magnitude(t_pos *v)
{
	return (sqrt((v->x * v->x) + (v->y * v->y) + (v->z * v->z)));
}
