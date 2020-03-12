/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_data_pr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htillman <htillman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 00:15:46 by htillman          #+#    #+#             */
/*   Updated: 2019/02/23 19:33:42 by htillman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_norm(t_node **tmp, t_k *k)
{
	(*tmp)->y = k->y;
	k->y++;
	(*tmp) = (*tmp)->next;
}

static void				ft_fd(char *file, t_k *k)
{
	k->i = 0;//fd
	if (((k->i) = open(file, O_RDONLY)) == -1)
	{
		ft_putstr("error\n");
		exit(-1);
	}
	k->y = 0; //y
	k->k = 1; //end
}

static void	ft_norm_two(t_k *k, t_node **head)
{
	if (close(k->i) == -1)
		ft_return("error: close");
	if (k->k == 0 && k->y == 0)
		ft_return("error: empty file");
	if (ft_validation(head) == -1)
		ft_return("error valid");
}

int						ft_create_ln_list(char *file, t_node **head)
{
	t_node				*tmp;
	char				*line;
	t_k					k;

	ft_fd(file, &k);
	while (k.k != 0)
	{
		k.k = get_next_line(k.i, &line);
		if (k.k == -1)
			ft_return("error gnl");
		if (k.k == 1 && line[0] == '\0')
			ft_return("error gnl str with only n");
		if (k.k == 0)
			break ;
		if (ft_first_val(line) == -1)
			ft_return("error first valid");
		if (!(tmp = ft_new_node(head)))
			ft_return("error: malloc lst");
		if (!(tmp->line = ft_strdup(line)))
			ft_return("error: malloc");
		free(line);
		ft_norm(&tmp, &k);
	}
	ft_norm_two(&k, head);
	return (0);
}
