/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iso.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htillman <htillman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 14:04:00 by htillman          #+#    #+#             */
/*   Updated: 2019/02/23 14:37:53 by htillman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_iso(t_mlx *m)
{
	m->cam.iso = 1;
	ft_print(*m);
	m->cam.iso = 0;
}

void	ft_tr_iso(t_dot *num)
{
	int	pr_x;
	int	pr_y;

	pr_x = num->x;
	pr_y = num->y;
	num->x = (pr_x - pr_y) * cos(0.523599);
	num->y = -1 * (num->z) + (pr_x + pr_y) * sin(0.523599);
}
