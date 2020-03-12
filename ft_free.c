/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odale-dr <odale-dr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 23:58:41 by htillman          #+#    #+#             */
/*   Updated: 2019/02/22 20:25:31 by odale-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_return(char *str)
{
	ft_putendl(str);
	exit(-1);
}

void		ft_free_dabl_mas(char ***map_line)
{
	size_t	i;

	i = 0;
	if ((*map_line) == NULL)
		return ;
	while (((*map_line)[i]) != NULL)
	{
		free((*map_line)[i]);
		i++;
	}
	free((*map_line));
}

int			ft_free_lst(t_node **head)
{
	t_node	*tmp;

	if (!(*head))
		return (-1);
	tmp = (*head)->next;
	while ((*head)->next != NULL)
	{
		free(*head);
		*head = tmp;
		tmp = tmp->next;
	}
	return (-1);
}

int			ft_free_with_line(char **line, t_node **head)
{
	free((*line));
	return (ft_free_lst(head));
}
