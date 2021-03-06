/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_control.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbalboa- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 13:38:56 by dbalboa-          #+#    #+#             */
/*   Updated: 2021/04/01 12:12:04 by dbalboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	direction_control(t_all *all, double x, double y)
{
	all->dir.x = x;
	all->dir.y = y;
}

void	plane_control(t_all *all, double x, double y)
{
	all->plane.x = x;
	all->plane.y = y;
}

void	player_control(t_all *all, int row, int column)
{
	all->control_player++;
	if (all->control_player > 1)
		error_put(11);
	all->pos.x = (double)row + 0.5;
	all->pos.y = (double)column + 0.5;
	if (all->map[row][column] == 'N')
	{
		direction_control(all, -1, 0);
		plane_control(all, 0, 0.66);
	}
	else if (all->map[row][column] == 'S')
	{
		direction_control(all, 1, 0);
		plane_control(all, 0, -0.66);
	}
	else if (all->map[row][column] == 'W')
	{
		direction_control(all, 0, -1);
		plane_control(all, -0.66, 0);
	}
	else if (all->map[row][column] == 'E')
	{
		direction_control(all, 0, 1);
		plane_control(all, 0.66, 0);
	}
}

void	sprite_control(t_all *all, int row, int column)
{
	all->sprite[all->sprite_count].x = (double)row + 0.5;
	all->sprite[all->sprite_count].y = (double)column + 0.5;
	all->sprite_count++;
}

void	sprite_init(t_all *all, int count)
{
	all->sprite = (t_dvec *)malloc(count * sizeof(t_dvec));
	if (!all->sprite)
		error_put(12);
	all->sprite_order = (int *)malloc(count * sizeof(int));
	if (!all->sprite_order)
		error_put(12);
	all->sprite_dist = (double *)malloc(count * sizeof(double));
	if (!all->sprite_dist)
		error_put(12);
}
