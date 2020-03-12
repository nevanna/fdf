/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_brasenham.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htillman <htillman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 17:49:18 by htillman          #+#    #+#             */
/*   Updated: 2019/02/23 18:27:52 by htillman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void				ft_int(t_double *k, t_b *b)
{
	k->x0 = (int)k->x0;
	k->y0 = (int)k->y0;
	k->x1 = (int)k->x1;
	k->y1 = (int)k->y1;
	b->i = 0;
}

static void				ft_x(t_double *k, t_b *b, t_mlx m)
{
	b->d = (b->dy << 1) - b->dx;
	b->d1 = b->dy << 1;
	b->d2 = (b->dy - b->dx) << 1;
	mlx_pixel_put(m.mlx_ptr, m.win_ptr, k->x0, k->y0, k->col);
	b->x = k->x0 + b->sx;
	b->y = k->y0;
	while (b->i < b->dx)
	{
		if (b->d > 0)
		{
			b->d += b->d2;
			b->y += b->sy;
		}
		else
			b->d += b->d1;
		mlx_pixel_put(m.mlx_ptr, m.win_ptr, b->x, b->y, k->col);
		b->x += b->sx;
		b->i++;
	}
}

static void				ft_y(t_double *k, t_b *b, t_mlx m)
{
	b->d = (b->dx << 1) - b->dy;
	b->d1 = b->dx << 1;
	b->d2 = (b->dx - b->dy) << 1;
	mlx_pixel_put(m.mlx_ptr, m.win_ptr, k->x0, k->y0, k->col);
	b->x = k->x0;
	b->y = k->y0 + b->sy;
	while (b->i < b->dy)
	{
		if (b->d > 0)
		{
			b->d += b->d2;
			b->x += b->sx;
		}
		else
			b->d += b->d1;
		mlx_pixel_put(m.mlx_ptr, m.win_ptr, b->x, b->y, k->col);
		b->y += b->sy;
		b->i++;
	}
}

void					ft_brasenham(t_double k, t_mlx m)
{
	t_b					b;

	ft_int(&k, &b);
	/*Изменения координат*/
	b.dx = (k.x1 > k.x0) ? (k.x1 - k.x0) : (k.x0 - k.x1);
	b.dy = (k.y1 > k.y0) ? k.y1 - k.y0 : (k.y0 - k.y1);
	/*Направление приращения*/
	b.sx = (k.x1 >= k.x0) ? (1) : (-1);
	b.sy = (k.y1 >= k.y0) ? (1) : (-1);
	if (b.dy < b.dx)
		ft_x(&k, &b, m);
	else
		ft_y(&k, &b, m);
}
