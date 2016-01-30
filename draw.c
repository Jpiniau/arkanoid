/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 11:33:20 by jpiniau           #+#    #+#             */
/*   Updated: 2016/01/30 14:41:39 by jpiniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"

static void		draw_ship(t_ship *ship)
{
	double x;
	double y;

	x = 2 * (ship->pos.x - 320) / 640;
	y = 2 * (240 - ship->pos.y) / 480;
	glColor3f(0.0f, 0.0f, 0.0f);
	glRectf(x, -0.75f, x + 0.2, -0.8f);

	//glVertex2d(ship->pos.x + ship->width, ship->pos.y - ship->height);
	//glVertex2d(ship->pos.x + ship->width, ship->pos.y);
	glEnd();
}
/*
static void		draw_ball(t_ball *ball)
{
	float	angle;
	int		i;

	float	theta;
	float	rad_x;
	float	rad_y;

	glBegin(GL_LINE_LOOP);
	i = -1;
	while(++i < 25)
	{
		theta = 2.0f * 3.1415926f * (float)i / (float)20;//get the current angle

		rad_x = 640/480*(ball->radius * cosf(theta));//calculate the x component
		rad_y = ball->radius * sinf(theta);//calculate the y component

		glVertex2f(x + rad_x, y + rad_y);//output vertex

	}
	glEnd();
}
*/
void			draw(t_env *env)
{
	draw_ship(&env->ship);
//	draw_ball(&env->ball);
}
