/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 11:33:20 by jpiniau           #+#    #+#             */
/*   Updated: 2016/01/30 12:42:34 by jpiniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"

void		draw_ship(t_ship *ship)
{
	double x;
	double y;

	x = 2 * (ship->pos.x - 320) / 640;
	y = 2 * (240 - ship->pos.y) / 480;
	glColor3f(0.0f, 0.0f, 0.0f);
	glRectf(x, -0.75f, x + 0.1, -0.8f);

	//glVertex2d(ship->pos.x + ship->width, ship->pos.y - ship->height);
	//glVertex2d(ship->pos.x + ship->width, ship->pos.y);
	glEnd();
}

