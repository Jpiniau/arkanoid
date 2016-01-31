/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scrore.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 18:52:30 by jpiniau           #+#    #+#             */
/*   Updated: 2016/01/31 19:07:55 by jpiniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"
#include <GLUT/glut.h>

void	score(t_env *env)
{
	size_t	i;
	char	*score;
	char	*life;

	i = -1;
	glColor3f(0.0f, 1.0f, 0.0f);
	glRasterPos2i(580, 20);
	score = ft_itoa(env->score);
	while (++i < ft_strlen(score))
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, score[i]);
	i = -1;
	life = ft_itoa(env->life);
	glRasterPos2i(20, 20);
	while (++i < ft_strlen(life))
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, life[i]);
}
