/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ball.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 18:26:57 by jpiniau           #+#    #+#             */
/*   Updated: 2016/01/31 17:29:09 by jpiniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"

void	move_ball(t_env *env)
{
	env->ball.pos.y += env->ball.speed.y;
	env->ball.pos.x += env->ball.speed.x;
	if (env->ball.pos.y >= HEIGHT || env->ball.pos.y <= 0)
		env->ball.speed.y *= -1;
	else if ((env->ball.pos.x >= env->ship.pos.x - env->ship.width &&
			env->ball.pos.x <= env->ship.pos.x + env->ship.width) &&
				(env->ball.pos.y == env->ship.pos.y - env->ship.height) &&
					env->ball.speed.y > 0)
		env->ball.speed.y *= -1;
	if (env->ball.pos.x >= WIDTH || env->ball.pos.x <= 0)
		env->ball.speed.x *= -1;
}
