/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arkanoid.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 18:44:41 by jpiniau           #+#    #+#             */
/*   Updated: 2016/01/31 19:04:59 by jpiniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARKANOID_H
# define ARKANOID_H

# include <GLFW/glfw3.h>
# include "libft.h"
# include <dirent.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>

# define WIDTH 640
# define HEIGHT 480

# define SHIP_SPEED 10
# define SHIP_WIDTH 30
# define SHIP_HEIGHT 5

# define BALL_SIZE 5
# define BALL_SPEED 5

typedef struct	s_pos
{
	double		x;
	double		y;
}				t_pos;

typedef struct	s_speed
{
	double		x;
	double		y;
}				t_speed;

typedef struct	s_ship
{
	t_pos		pos;
	double		width;
	double		height;
	double		speed;
	double		dir;
}				t_ship;

typedef struct	s_ball
{
	t_pos		pos;
	t_speed		speed;
	float		radius;
}				t_ball;

typedef struct	s_brick
{
	t_pos		pos;
	double		width;
	double		height;
	char		val;
}				t_brick;

typedef struct	s_map
{
	t_brick		**map;
	int			height;
	int			width;
}				t_map;

typedef struct	s_env
{
	t_ship		ship;
	GLFWwindow	*win;
	t_ball		ball;
	t_map		*maps;
	int			set;
	double		score;
	int			nblvl;
	int			lvl;
	int			life;

}				t_env;

void			draw(t_env *env);
void			init(t_env *env);
void			content(t_env *env);
void			key_hook(t_env *env);
void			ship_pos(t_env *env, double new_pos);
void			move_ball(t_env *env);
t_map			*parse_maps(t_map *maps, t_env *env);
void			score(t_env *env);

#endif
