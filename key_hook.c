#include "arkanoid.h"

void	key_hook(t_env *env)
{
	double x;

	x = 2 * (env->ship.pos.x - 320) / 640;
	glfwPollEvents();
	if (glfwGetKey(env->win, GLFW_KEY_LEFT) == GLFW_PRESS)
		ship_pos(env, x - SHIP_SPEED);
	if (glfwGetKey(env->win, GLFW_KEY_RIGHT) == GLFW_PRESS)
		ship_pos(env, x + SHIP_SPEED);
}
