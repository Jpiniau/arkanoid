/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 11:29:54 by jpiniau           #+#    #+#             */
/*   Updated: 2016/01/30 12:34:40 by jpiniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"

int		main()
{
	t_env	env;

	init(&env);
	while (!glfwWindowShouldClose(env.win))
	{
		content(&env);
		glfwSwapBuffers(env.win);
	}
	glfwDestroyWindow(env.win);
	glfwTerminate();
	return (0);
}
