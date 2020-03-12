/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htillman <htillman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 22:31:15 by htillman          #+#    #+#             */
/*   Updated: 2019/02/23 19:08:49 by htillman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void			ft_left_and_down_point(t_mlx *m, t_node *node)
{
	int				i;

	i = 0;
	while (i < (m->head->len))
	{
		m->k.x0 = node->num[i].x * m->cam.scale + m->cam.offset_x;
		m->k.y0 = node->num[i].y * m->cam.scale + m->cam.offset_y;
		m->k.x1 = node->num[i + 1].x * m->cam.scale + m->cam.offset_x;
		m->k.y1 = node->num[i + 1].y * m->cam.scale + m->cam.offset_y;
		m->k.col = node->num[i + 1].color;
		if (i != ((m->head->len) - 1))
			ft_brasenham(m->k, *m);
		if (node->next != NULL)
		{
			m->k.x1 = node->next->num[i].x * m->cam.scale + m->cam.offset_x;
			m->k.y1 = node->next->num[i].y * m->cam.scale + m->cam.offset_y;
			m->k.col = node->next->num[i].color;
			ft_brasenham(m->k, *m);
		}
		i++;
	}
}

static void			ft_go_num(t_dot *num, int len, t_mlx m)
{
	int				i;

	i = 0;
	if (m.cam.iso == 1)
		while (i < len)
			ft_tr_iso(&num[i++]);
	else
	{
		while (i < len)
		{
			ft_rotate_x(m.cam.angl_a, &num[i]);
			ft_rotate_y(m.cam.angl_b, &num[i]);
			i++;
		}
	}
}

void				ft_print(t_mlx m)
{
	t_node			*new_head;
	t_node			*tmp;

	new_head = NULL;
	ft_lst_cpy(&new_head, m.head);
	mlx_clear_window(m.mlx_ptr, m.win_ptr);
	tmp = new_head;
	while (tmp != NULL)
	{
		ft_go_num(tmp->num, tmp->len, m);
		tmp = tmp->next;
	}
	tmp = new_head;
	while (tmp->next != NULL)
	{
		ft_left_and_down_point(&m, tmp);
		tmp = tmp->next;
	}
	ft_left_and_down_point(&m, tmp);
	ft_free_lst(&new_head);
}
