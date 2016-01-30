/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 11:33:20 by jpiniau           #+#    #+#             */
/*   Updated: 2016/01/30 16:28:20 by jpiniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"

static void		draw_ship(t_ship *ship)
{
	double x;
	double y;

	//x = 2 * (ship->pos.x - 320) / 640;
	x = ship->pos.x;
	//y = 2 * (240 - ship->pos.y) / 480;
	y = ship->pos.y;
	glColor3f(0.0f, 0.0f, 0.0f);
	glRecti(x - 15, y + 5, x + 15, y - 5);
	//glRecti(150, 50, 160, 55);
}

static void		draw_ball(t_ball *ball)
{
	double x;
	double y;

	x = 2 * (ball->pos.x - 320) / 640;
	y = 2 * (240 - ball->pos.y) / 480;
	glColor3f(0.7f, 1.0f, 0.7f);
	glRectf(x, y, x + 0.02f, y - 0.02f);

}

void			draw(t_env *env)
{
	draw_ship(&env->ship);
	draw_ball(&env->ball);
}
