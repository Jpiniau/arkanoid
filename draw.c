/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 11:33:20 by jpiniau           #+#    #+#             */
/*   Updated: 2016/01/31 17:44:09 by jpiniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"

static void		draw_ship(t_ship *ship)
{
	double x;
	double y;
	double w;
	double h;

	x = ship->pos.x;
	y = ship->pos.y;
	w = ship->width;
	h = ship->height;
	glColor3f(0.0f, 0.0f, 0.0f);
	glRecti(x - w, y - h, x + w, y + h);
}

static void		draw_ball(t_ball *ball)
{
	double x;
	double y;

	x = ball->pos.x;
	y = ball->pos.y;
	glColor3f(0.9f, 0.7f, 0.7f);
	glRecti(x - 5, y + 5, x + 5, y - 5);
}

static void		draw_map(t_brick **map)
{
	int		i;
	double	x;
	double	y;

	i = -1;
	while (++i < 140)
	{
		if (map[i][0].val != '0')
		{
			x = map[i][0].pos.x;
			y = map[i][0].pos.y;
			glColor3f(0.5f, 0.5f, 0.5f);
			glRecti(x, y, x + map[i][0].width, y + map[i][0].height);
		}
	}
}

void			draw(t_env *env)
{
	draw_ship(&env->ship);
	draw_ball(&env->ball);
	draw_map(env->maps[0].map);
}
