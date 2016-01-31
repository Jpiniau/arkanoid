/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 11:29:54 by jpiniau           #+#    #+#             */
/*   Updated: 2016/01/30 18:39:55 by jpiniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"

int		main(void)
{
	t_env	env;

	init(&env);
	while (!glfwWindowShouldClose(env.win))
	{
		glViewport(0, 0, WIDTH, HEIGHT);
		content(&env);
		glfwSwapBuffers(env.win);
	}
	glfwDestroyWindow(env.win);
	glfwTerminate();
	return (0);
}
