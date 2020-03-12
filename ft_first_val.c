/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_first_val.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htillman <htillman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 16:44:26 by htillman          #+#    #+#             */
/*   Updated: 2019/02/23 19:27:01 by htillman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int			ft_six(char c)
{
	if (c >= '0' && c <= '9')
		return (0);
	if (c >= 'A' && c <= 'F')
		return (0);
	if (c >= 'a' && c <= 'f')
		return (0);
	if (c == 'x')
		return (0);
	if (c == ',')
		return (0);
	if (c == '-')
		return (0);
	ft_return("error: validation");
	return (-1);
}

static int			ft_start_and_end(char *line, int len)
{
	len = len - 1;
	if (line[0] == '-' || (line[0] >= '0' && line[0] <= '9') || line[0] == ' ')
	{
		while (line[len] == ' ')
			len--;
		if ((line[len] >= '0' && line[len] <= '9') ||
			(line[len] >= 'A' && line[len] <= 'F') ||
			(line[len] >= 'a' && line[len] <= 'f'))
			return (0);
	}
	ft_return("error: validation");
	return (-1);
}

int					ft_first_val(char *line)
{
	int				i;
	int				flag;
	int				len;

	flag = 1;
	i = 0;
	len = ft_strlen(line);
	while (line[i] != '\0')
	{
		if (line[i] != ' ')
			if (ft_six(line[i]) == -1)
				ft_return("error: validation");
		i++;
	}
	if (ft_start_and_end(line, len) == -1)
		ft_return("error: validation");
	return (0);
}
