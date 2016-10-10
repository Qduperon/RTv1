/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RTv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduperon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 16:08:43 by qduperon          #+#    #+#             */
/*   Updated: 2016/10/10 20:10:36 by qduperon         ###   ########.fr       */
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

typedef	struct		s_cone
{
	double			alpha;
	t_color			color;
	t_pos			pos;
	struct s_cone	*next;
}					t_cone;

typedef struct		s_cylind
{
	double			radius;
	t_color			color;
	t_pos			pos;
	struct s_cylind	*next;
}					t_cylind;

typedef struct		s_plan
{
	double			dis;
	t_color			color;
	t_pos			pos;
	struct s_plan	*next;
}					t_plan;

typedef struct		s_sphere
{
	double			radius;
	t_color			color;
	t_pos			pos;
	struct s_sphere	*next;
}					 t_sphere;

typedef struct		s_spot
{
	t_color			color;
	t_pos			pos;
	struct s_spot	*next;
}					t_spot;

typedef struct		s_scene
{
	t_cam			*cam;
	t_cone			*cone;
	t_cylind		*cylind;
	t_plan			*plan;
	t_sphere		*sphere;
	t_spot			*spot;
}					t_scene;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	t_img			img;
}					t_env;

/*
** camera.c
*/
t_cam				*ft_get_camera(int fd);
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
t_cam				*ft_new_camera(t_pos pos, t_pos dir);
t_scene				*ft_get_scene(void);
void				ft_init_scene(char *scene);
/*
** parser.c
*/
void				ft_parser(char *av, t_env *env);
void				ft_camera(char *line, t_env *env);
void				ft_RTv1(char *scene);
/*
** tools_vect.c
*/
double				ft_magnitude(t_pos *v);
t_pos				*ft_neg(t_pos *v);
t_pos				*ft_norm(t_pos *v);
/*
** vect.c
*/
t_pos				*ft_new_vector(double x, double y, double z);
t_pos				*ft_vector(int fd);
void				ft_deleted_vect(t_pos *vect);

#endif
