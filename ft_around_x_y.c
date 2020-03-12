/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_around_x_y.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odale-dr <odale-dr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 18:38:23 by htillman          #+#    #+#             */
/*   Updated: 2019/02/22 20:25:41 by odale-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_rotate_x(double angle, t_dot *num)
{
	int	pr_y;

	pr_y = num->y;
	num->y = pr_y * cos(angle) - num->z * sin(angle);
	num->z = (1) * pr_y * sin(angle) + num->z * cos(angle);
}

void	ft_rotate_y(double angle, t_dot *num)
{
	int	pr_x;

	pr_x = num->x;
	num->x = pr_x * cos(angle) - num->z * sin(angle);
	num->z = (1) * pr_x * sin(angle) + num->z * cos(angle);
}

void	ft_rotate_z(double angle, t_dot *num)
{
	int	pr_x;
	int	pr_y;

	pr_x = num->x;
	pr_y = num->y;
	num->x = pr_x * cos(angle) + pr_y * sin(angle);
	num->y = (-1) * pr_x * sin(angle) + pr_y * cos(angle);
}
