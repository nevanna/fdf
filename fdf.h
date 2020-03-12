/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htillman <htillman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 20:22:56 by htillman          #+#    #+#             */
/*   Updated: 2019/02/23 21:51:17 by htillman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>
# include "minilibx_macos/mlx.h"

typedef struct		s_dot
{
	double			x;
	double			y;
	double			z;
	int				color;
}					t_dot;

typedef struct		s_double
{
	double			x0;
	double			y0;
	double			x1;
	double			y1;
	int				col;
}					t_double;

typedef struct		s_node{
	char			*line;
	char			**map_line;
	int				y;
	int				len;
	t_dot			*num;
	struct s_node	*next;
}					t_node;
typedef struct		s_camera
{
	double			offset_x;
	double			offset_y;
	double			scale;
	double			angl_x;
	double			angl_y;
	double			angl_a;
	double			angl_b;
	double			dx;
	double			dy;
	double			dz;
	double			kx;
	double			ky;
	double			kz;
	double			iso;
}					t_camera;

typedef struct		s_b
{
	int				dx;
	int				dy;
	int				sx;
	int				sy;
	int				d;
	int				d1;
	int				d2;
	int				x;
	int				y;
	int				i;
}					t_b;

typedef struct		s_k
{

	int				y;
	int				i;
	int				k;
	int				len;

}					t_k;

typedef struct		s_mlx
{
	void			*mlx_ptr;
	void			*win_ptr;
	int				xwin;
	int				ywin;
	int				col;
	t_node			*head;
	t_camera		cam;
	t_double		k;
}					t_mlx;

t_node				*ft_new_node(t_node **head);
int					ft_create_ln_list(char *file, t_node **head);
int					ft_first_val(char *line);
int					ft_validation(t_node **head);
void				ft_free_dabl_mas(char ***map_line);
int					ft_free_with_line(char **line, t_node **head);
int					ft_free_lst(t_node **head);
void				ft_return(char *str);
int					ft_to_ten(char *word, int st);
int					ft_maslen(char **mas);
double				ft_dig_to_rad(int angle);
void				ft_cam(t_mlx *m);
//void				ft_print_lst(t_node **head);
//void				ft_print_st(t_dot *num, int len);
//void				ft_print_mas(char **mas);
void				ft_print(t_mlx	m);
void				ft_key(t_mlx *m);
void				ft_brasenham(t_double k, t_mlx m);
void				ft_rotate_x(double angle, t_dot *num);
void				ft_rotate_y(double angle, t_dot *num);
void				ft_rotate_z(double angle, t_dot *num);
void				ft_tr_iso(t_dot *num);
void				ft_left(t_mlx *m);
void				ft_right(t_mlx *m);
void				ft_up(t_mlx *m);
void				ft_down(t_mlx *m);
void				ft_off_y_incr(t_mlx *m);
void				ft_plus(t_mlx *m);
void				ft_minus(t_mlx *m);
void				ft_off_y_dec(t_mlx *m);
void				ft_off_x_dec(t_mlx *m);
void				ft_off_x_incr(t_mlx *m);
void				ft_iso(t_mlx *m);
void				ft_lst_cpy(t_node **new_head, t_node *old_head);
#endif
