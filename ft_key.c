/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htillman <htillman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 20:34:29 by htillman          #+#    #+#             */
/*   Updated: 2019/02/23 21:08:34 by htillman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int				ft_exit_x(t_mlx *m)
{
	mlx_destroy_window(m->mlx_ptr, m->win_ptr);
	exit(1);
}

static int				ft_ch_key_i(int key, t_mlx *m)
{
	if (key == 1)
		ft_off_y_incr(m);
	if (key == 13)
		ft_off_y_dec(m);
	if (key == 2)
		ft_off_x_incr(m);
	if (key == 0)
		ft_off_x_dec(m);
	if (key == 34)
		ft_iso(m);
	return (0);
}

static int				ft_ch_key(int key, t_mlx *m)
{
	if (key == 53)
		ft_exit_x(m);
	if (key == 69)
		ft_plus(m);
	if (key == 78)
		ft_minus(m);
	if (key == 123)
		ft_left(m);
	if (key == 126)
		ft_up(m);
	if (key == 124)
		ft_right(m);
	if (key == 125)
		ft_down(m);
	ft_ch_key_i(key, m);
	return (0);
}

void					ft_key(t_mlx *m)
{
	mlx_key_hook(m->win_ptr, ft_ch_key, m);
	mlx_hook(m->win_ptr, 17, 0, ft_exit_x, m);
}
