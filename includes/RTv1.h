/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RTv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduperon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 16:08:43 by qduperon          #+#    #+#             */
/*   Updated: 2016/10/07 20:04:36 by qduperon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include <fcntl.h>
# include <stdlib.h>
# include "../libft/includes/libft.h"
# include "../minilibx_macos/mlx.h"

# define HEIGHT	750
# define WIDTH	750

typedef	struct		s_pos
{
	double			x;
	double			y;
	double			z;
}					t_pos;

typedef	struct		s_color
{
	double			red;
	double			green;
	double			blue;	
}					t_color;

typedef struct		s_img
{
	char			*data;
	int				bpp;
	int				endian;
	int				sl;
	void			*img;	
}					t_img;

typedef	struct		s_cam
{
	t_pos			pos;
	t_pos			dir;
}					t_cam;

typedef struct		s_spot
{
	t_color			color;
	t_pos			pos;
	struct	s_spot	*next;
}					t_spot;

typedef struct		s_obj
{
	char			*type;
	double			data;
	t_color			color;
	t_pos			pos;
	struct s_obj	*next;
}					 t_obj;

typedef struct		s_env
{
	t_cam			*cam;
	t_img			*img;
	void			*mlx;
	void			*win;
}					t_env;

/*
** clear.c
*/
void				ft_clear_obj(t_obj **begin_list);
void				ft_clear_spot(t_spot **begin_list);
/*
** error.c
*/
void				ft_error(void);
void				ft_exit(char *s);
void				ft_free(t_env *env);
void				ft_free_error(t_env *env);
/*
** init.c
*/
t_cam				*ft_init_cam(void);
/*
** parser.c
*/
void				ft_parser(char *av, t_env *env);
void				ft_camera(char *line, t_env *env);

#endif
