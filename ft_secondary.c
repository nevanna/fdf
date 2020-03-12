/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_secondary.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htillman <htillman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 17:58:54 by htillman          #+#    #+#             */
/*   Updated: 2019/02/23 21:09:25 by htillman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				ft_maslen(char **mas)
{
	int			i;

	i = 0;
	while (mas[i] != NULL)
		i++;
	return (i);
}

double			ft_dig_to_rad(int angle)
{
	double		new_angl;
	double		pi;

	pi = 3.1415926535;
	new_angl = (((double)angle) * pi) / 180.0f;
	return (new_angl);
}

void			ft_cam(t_mlx *m)
{
	t_node		*tmp;

	tmp = m->head;
	while (tmp->next != NULL)
		tmp = tmp->next;
	if ((m->xwin) / (tmp->len) < ((m->ywin) / tmp->num[0].y))
		m->cam.scale = ((m->xwin) / (tmp->len)) / 2;
	else
		m->cam.scale = ((m->ywin) / tmp->num[0].y) / 2;
	m->cam.offset_x = (m->xwin) / 2;
	m->cam.offset_y = (m->ywin) / 2;
}
