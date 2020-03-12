/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htillman <htillman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 16:44:18 by htillman          #+#    #+#             */
/*   Updated: 2019/02/23 21:09:15 by htillman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//создаю список, через гнл сразу закидываю строку в списки
//зачем мне заниматьпамять строкойб, еслии ее можно использовать как буфер и сразу сплитить
//и в лист записываь двумерный массив, который будет состоять из цифр, их можно переписывать сразу
// в интовый массив или дабловский сколько строк в двумерном массиве столько чисел в строке
//тогда будет у нас одномерный массив или три массива? из интовдаблов длиной мах маплайн
//структура из трех yxz, их по максимуму

void				ft_init(t_mlx *m, t_node *head)
{
	m->xwin = 2000;
	m->ywin = 1200;
	m->mlx_ptr = mlx_init();
	if ((m->win_ptr = mlx_new_window(m->mlx_ptr, m->xwin, m->ywin, "mlx 42")) == NULL)
		ft_return("error: mlx->win");
	m->head = head;
	m->cam.angl_a = ft_dig_to_rad(35);
	m->cam.angl_b = ft_dig_to_rad(45);
	m->cam.angl_x = 0.5;
	m->cam.angl_y = 0.5;
	m->cam.kx = 1;
	m->cam.ky = 1;
	m->cam.kz = 1;
	m->cam.iso = 0;
	ft_cam(m);
}

int					main(int argc, char **argv)
{
	t_node			*head;
	t_mlx			m;

	head = NULL;
	if (argc != 2)
	{
		ft_putstr("Usage: ./fdf source_file\n");
		return (-1);
	}
	if (ft_create_ln_list(argv[1], &head) == -1)
	{
		ft_putstr("main:error\n");
		exit(-1);
	}
	ft_putendl("valid ok");
	ft_init(&m, head);
	ft_print(m);
	ft_key(&m);
	mlx_loop(m.mlx_ptr);
	return (1);
}
