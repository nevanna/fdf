/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_cpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odale-dr <odale-dr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 22:03:32 by htillman          #+#    #+#             */
/*   Updated: 2019/02/22 20:25:36 by odale-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_fill_num(t_node **new_tmp, t_dot *num)
{
	int		i;

	i = 0;
	while (i < (*new_tmp)->len)
	{
		(*new_tmp)->num[i].x = num[i].x;
		(*new_tmp)->num[i].y = num[i].y;
		(*new_tmp)->num[i].z = num[i].z;
		(*new_tmp)->num[i].color = num[i].color;
		i++;
	}
}

void		ft_lst_cpy(t_node **new_head, t_node *old_head)
{
	t_k		k;
	t_node	*tmp;
	t_node	*new_tmp;

	k.i = 0;
	tmp = old_head;
	k.len = tmp->len;
	while (tmp->next != NULL)
		tmp = tmp->next;
	k.y = tmp->y;
	tmp = old_head;
	while (k.i++ <= k.y)
	{
		new_tmp = ft_new_node(new_head);
		new_tmp->len = tmp->len;
		new_tmp->y = tmp->y;
		if (!(new_tmp->num = (t_dot*)malloc(sizeof(t_dot) * (tmp->len))))
			ft_return("error: malloc");
		ft_fill_num(&(new_tmp), tmp->num);
		tmp = tmp->next;
		new_tmp = new_tmp->next;
	}
}
