/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odale-dr <odale-dr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 23:57:10 by htillman          #+#    #+#             */
/*   Updated: 2019/02/22 17:48:39 by odale-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_left(t_mlx *m)
{
	m->cam.angl_b = m->cam.angl_b + ft_dig_to_rad(10);
	ft_print(*m);
}

void	ft_right(t_mlx *m)
{
	m->cam.angl_b = m->cam.angl_b - ft_dig_to_rad(10);
	ft_print(*m);
}

void	ft_up(t_mlx *m)
{
	m->cam.angl_a = m->cam.angl_a + ft_dig_to_rad(10);
	ft_print(*m);
}

void	ft_down(t_mlx *m)
{
	m->cam.angl_a = m->cam.angl_a - ft_dig_to_rad(10);
	ft_print(*m);
}

void	ft_off_y_incr(t_mlx *m)
{
	m->cam.offset_y = m->cam.offset_y + 10;
	ft_print(*m);
}
