#include "arkanoid.h"

void	key_hook(t_env *env)
{
	glfwPollEvents();
	if (glfwGetKey(env->win, GLFW_KEY_LEFT) == GLFW_PRESS)
		ship_pos(env, env->ship.pos.x - SHIP_SPEED);
	if (glfwGetKey(env->win, GLFW_KEY_RIGHT) == GLFW_PRESS)
		ship_pos(env, env->ship.pos.x + SHIP_SPEED);
}
