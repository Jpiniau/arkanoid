#include "arkanoid.h"

void	ship_pos(t_env *env, double new_pos)
{
	if (new_pos > -1 && new_pos <= 1 - 0.2)
		env->ship.pos.x = (new_pos / 2) * 640 + 320;
}
