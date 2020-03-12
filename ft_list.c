/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odale-dr <odale-dr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 19:52:56 by htillman          #+#    #+#             */
/*   Updated: 2019/02/22 20:25:37 by odale-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_node		*ft_new_node(t_node **head)
{
	t_node	*new;
	t_node	*toend;

	toend = NULL;
	if (!(new = (t_node*)malloc(sizeof(t_node))))
	{
		if ((*head) == NULL)
			return (NULL);
		else
		{
			ft_free_lst(head);
			ft_return("error: malloc");
		}
	}
	new->next = NULL;
	if ((*head) == NULL)
	{
		(*head) = new;
		return (new);
	}
	toend = *head;
	while (toend->next != NULL)
		toend = toend->next;
	toend->next = new;
	return (new);
}
