/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 11:13:54 by jpiniau           #+#    #+#             */
/*   Updated: 2016/01/31 17:43:50 by jpiniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"
/*
static void			key_callback(GLFWwindow *window, int key, int scancode, int action, int mods)
{
	(void)scancode;
	(void)mods;
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
	{
		ft_putstr("bye");
		glfwSetWindowShouldClose(window, GL_TRUE);
	}
}
*/
static GLFWwindow	*init_window(void)
{
	GLFWwindow *window;

	if (!glfwInit())
		return (NULL);
	window = glfwCreateWindow(WIDTH, HEIGHT, "Arkanoid", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return (NULL);
	}
	glfwMakeContextCurrent(window);
//	glfwSetKeyCallback(window, key_callback);
	return (window);
}

static void			init_ship(t_ship *ship)
{
	ship->pos.x = WIDTH / 2;
	ship->pos.y = HEIGHT - 30;
	ship->width = SHIP_WIDTH;
	ship->height = SHIP_HEIGHT;
}

static void			init_ball(t_ball *ball)
{
	ball->pos.x = WIDTH / 2;
	ball->pos.y = 400;
	ball->speed.x = 3;
	ball->speed.y = 5;
	ball->radius = 0.03;
}

void				test(t_map *maps)
{
	int i = -1;

	(void)i;
	ft_putendl("test affichage map");
	while (++i < 135)
	{
		ft_putchar(maps[0].map[i][0].val);
		if ((i + 1) % 9 == 0 && i > 0)
			ft_putchar('\n');
	}
	ft_putchar('\n');
}

void				init(t_env *env)
{
	env->win = init_window();
	init_ship(&env->ship);
	init_ball(&env->ball);
	env->maps = parse_maps(env->maps);
	//test(env->maps);
}
