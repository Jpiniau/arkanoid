#ifndef ARKANOID_H
# define ARKANOID_H

# include <GLFW/glfw3.h>
# include "libft.h"

# define SHIP_SPEED 20
# define SHIP_WIDTH 0.40
# define SHIP_HEIGHT 0.05

typedef struct	s_pos
{
	double	x;
	double	y;
}				t_pos;

typedef struct	s_ship
{
	t_pos	pos;
	double	width;
	double	height;
}				t_ship;

typedef struct	s_env
{
	t_ship		ship;
	GLFWwindow	*win;

}				t_env;


void	draw_ship(t_ship *ship);
void	init(t_env *env);
void	content(t_env *env);
void	key_hook(t_env *env);
void	ship_pos(t_env *env, double new_pos);

#endif
