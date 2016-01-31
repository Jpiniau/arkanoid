/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 18:39:19 by jpiniau           #+#    #+#             */
/*   Updated: 2016/01/31 17:43:33 by jpiniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"

void	key_hook(t_env *env)
{
	double x;

	x = env->ship.pos.x;
	glfwPollEvents();
	if (glfwGetKey(env->win, GLFW_KEY_LEFT) == GLFW_PRESS)
	{
		ship_pos(env, x - SHIP_SPEED);
		env->ship.dir = 0;
	}
	if (glfwGetKey(env->win, GLFW_KEY_RIGHT) == GLFW_PRESS)
	{
		ship_pos(env, x + SHIP_SPEED);
		env->ship.dir = 1;
	}
	if (glfwGetKey(env->win, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		ft_putstr("bye");
		glfwSetWindowShouldClose(env->win, GL_TRUE);
	}
}
