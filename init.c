/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 11:13:54 by jpiniau           #+#    #+#             */
/*   Updated: 2016/01/30 12:43:17 by jpiniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	(void)scancode;
	(void)mods;
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
	{
		ft_putstr("bye");
		glfwSetWindowShouldClose(window, GL_TRUE);
	}
}

static GLFWwindow	*init_window()
{
	GLFWwindow* window;

	if(!glfwInit())
		return NULL ;
	window = glfwCreateWindow(640, 480, "Arkanoid", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return NULL;
	}
	glfwMakeContextCurrent(window);
	glfwSetKeyCallback(window, key_callback);
	return window;
}

static void			init_ship(t_ship *ship)
{
	ship->pos.x = 0;
	ship->pos.y = 400;
	ship->width = SHIP_WIDTH;
	ship->height = SHIP_HEIGHT;
}

void				init(t_env *env)
{
	env->win = init_window();
	init_ship(&env->ship);
}

