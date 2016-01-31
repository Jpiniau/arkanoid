/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 17:31:52 by jpiniau           #+#    #+#             */
/*   Updated: 2016/01/31 17:31:55 by jpiniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void		draw_one_brick(t_brick *brick)
{
	glBegin(GL_QUADS);
	if (brick->state != 9)
	{
		if (brick->state == 1)
			glColor3ub(125, 0, 0);
		else if (brick->state == 2)
			glColor3ub(0, 125, 0);
		else if (brick->state == 3)
			glColor3ub(0, 0, 125);
	}
	else
		glColor3ub(255, 255, 255);
	glRecti(brick->pos.x, brick->pos.y);
	glRecti(brick->pos.x, brick->pos.y - brick->height);
	glRecti(brick->pos.x + brick->width, brick->pos.y - brick->height);
	glRecti(brick->pos.x + brick->width, brick->pos.y);
	glEnd();
}

static void		draw_bricks(t_map *map)
{
	int i;
	int j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->map[i][j].state >= 1)
				draw_one_brick(&map->map[i][j]);
			j++;
		}
		i++;
	}
}
