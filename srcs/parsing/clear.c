/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduperon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 15:04:30 by qduperon          #+#    #+#             */
/*   Updated: 2016/12/23 15:04:31 by qduperon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rtv1.h"

void		ft_clear_obj(t_obj **start)
{
	t_obj	*tmp;

	while (*start != NULL)
	{
		tmp = (*start)->next;
		(*start)->next = NULL;
		free(*start);
		*start = tmp;
	}
}

void		ft_clear_spot(t_spot **start)
{
	t_spot	*tmp;

	while (*start != NULL)
	{
		tmp = (*start)->next;
		(*start)->next = NULL;
		free(*start);
		*start = tmp;
	}
}
