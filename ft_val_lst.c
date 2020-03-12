/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_val_lst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htillman <htillman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 17:50:40 by htillman          #+#    #+#             */
/*   Updated: 2019/02/23 19:02:05 by htillman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int			ft_to_color(char *word, int i)
{
	int				k;
	int				st;

	k = 0;
	st = i;
	while (word[i] != '\0')
	{
		if ((word[i] >= '0' && word[i] <= '9') ||
			(word[i] >= 'A' && word[i] <= 'F') ||
			(word[i] >= 'a' && word[i] <= 'f'))
		{
			i++;
			k++;
		}
		else
			return (-1);
		if (k > 6)
			return (-1);
	}
	return (ft_to_ten(word, st));
}

static int			ft_get_color(char *word, int *color, double *z)
{
	int				i;
	int				flag;

	flag = 0;
	while (z)
		break ;
	i = ft_strlen((word)) - 9;
	if (word[i] != ',')
		return (-1);
	if (word[i + 1] == '0' && word[i + 2] == 'x')
	{
		i = i + 3;
		if ((*color = ft_to_color(word, i)) == -1)
			return (-1);
	}
	return (0);
}

static int			ft_is_only_nb(char *word)
{
	int				i;

	i = 0;
	if (word[i] == '-')
		i++;
	while (word[i] != '\0')
	{
		if (!(word[i] >= '0' && word[i] <= '9'))
			return (-1);
		i++;
	}
	return (0);
}

static int			ft_what_is_that(char **map_line, t_dot *num, int y)
{
	int				i;

	i = 0;
	if (map_line[i] == NULL)
		return (-1);
	while (map_line[i] != NULL)
	{
		num[i].x = i;
		num[i].y = y;
		if (ft_is_only_nb(map_line[i]) == 0)
		{
			(num[i]).z = ft_atoi(map_line[i]);
			(num[i]).color = 16777215;
		}
		else
		{
			if (ft_get_color(map_line[i], &(num[i].color), &(num[i].z)) == -1)
				return (-1);
			num[i].z = ft_atoi(map_line[i]);
		}
		i++;
	}
	return (0);
}

int					ft_validation(t_node **head)
{
	t_node			*tmp;
	int				control;

	tmp = (*head);
	control = -2;
	while (tmp != NULL)
	{
		if ((tmp->map_line = ft_strsplit(tmp->line, ' ')) == NULL)
			ft_return("error split malloc");
		tmp->len = ft_maslen(tmp->map_line);
		if (control == -2)
			control = tmp->len;
		else if (control != tmp->len)
			ft_return("error len");
		if (!(tmp->num = (t_dot *)malloc(sizeof(t_dot) * (tmp->len))))
			ft_return("error malloc");
		if (ft_what_is_that(tmp->map_line, tmp->num, tmp->y) == -1)
			ft_return("error what is that");
		ft_free_dabl_mas(&(tmp->map_line));
		ft_strdel(&(tmp->line));
		tmp = tmp->next;
	}
	return (0);
}
