/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_t.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odale-dr <odale-dr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 00:00:17 by htillman          #+#    #+#             */
/*   Updated: 2019/02/22 20:25:40 by odale-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_plus(t_mlx *m)
{
	m->cam.scale = m->cam.scale * 1.1;
	ft_print(*m);
}

void	ft_minus(t_mlx *m)
{
	m->cam.scale = m->cam.scale / 1.1;
	ft_print(*m);
}

void	ft_off_y_dec(t_mlx *m)
{
	m->cam.offset_y = m->cam.offset_y - 10;
	ft_print(*m);
}

void	ft_off_x_dec(t_mlx *m)
{
	m->cam.offset_x = m->cam.offset_x - 10;
	ft_print(*m);
}

void	ft_off_x_incr(t_mlx *m)
{
	m->cam.offset_x = m->cam.offset_x + 10;
	ft_print(*m);
}
