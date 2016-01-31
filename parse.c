/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 21:27:38 by jpiniau           #+#    #+#             */
/*   Updated: 2016/01/31 19:12:44 by jpiniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"

static char			*create_map(char *line)
{
	static char		*tmp = NULL;

	if (tmp == NULL)
		tmp = ft_strnew(1);
	tmp = ft_strjoin(tmp, line);
	tmp = ft_strjoin(tmp, " ");
	return (tmp);
}

static t_brick		*set_brick(t_brick *brick, int posx, int posy, int val)
{
	brick = (t_brick *)ft_memalloc(sizeof(t_brick));
	brick->pos.x = posx;
	brick->pos.y = posy;
	brick->width = WIDTH / 10 - 1;
	brick->height = HEIGHT / 15 - 1;
	brick->val = val;
	return (brick);
}

static t_brick		**set_bricks(t_brick **bricks, char **tmp_bricks)
{
	size_t		i;
	size_t		ii;
	size_t		j;
	int			w;
	int			h;

	i = 0;
	j = -1;
	w = WIDTH / 10;
	h = HEIGHT / 15;
	while (tmp_bricks[i])
	{
		bricks[i] = set_brick(bricks[i], ii * w, j * h, tmp_bricks[i][0]);
		ii++;
		if ((i + 1) % 10 == 0)
		{
			ii = 0;
			j++;
		}
		i++;
	}
	return (bricks);
}

static t_brick		**parse_map(t_brick **map, char *name_file)
{
	int		fd;
	char	*line;
	char	*tmp;

	(void)map;
	tmp = NULL;
	name_file = ft_strjoin("./levels/", name_file);
	if ((fd = open(name_file, O_RDONLY)) <= -1)
		exit(-1);
	while (get_next_line(fd, &line) > 0)
	{
		if (!(tmp = create_map(line)))
			exit(-1);
		free(line);
	}
	map = (t_brick **)ft_memalloc(sizeof(t_brick *) * ft_strlen(tmp));
	map = set_bricks(map, ft_strsplit(tmp, ' '));
	free(name_file);
	free(tmp);
	free(line);
	close(fd);
	return (map);
}

t_map				*parse_maps(t_map *maps, t_env *env)
{
	DIR				*dirp;
	DIR				*tmp;
	struct dirent	*dr;
	int				i;
	int				nblvl;

	i = 0;
	if ((dirp = opendir("./levels/")) != NULL &&
			(tmp = opendir("./levels/")) != NULL)
	{
		nblvl = ft_lendir(tmp);
		env->nblvl = nblvl;
		maps = (t_map *)ft_memalloc(sizeof(t_map) * nblvl);
		while ((dr = readdir(dirp)))
		{
			if (!ft_strequ(dr->d_name, ".") && !ft_strequ(dr->d_name, ".."))
			{
				maps[i].map = parse_map(maps[i].map, dr->d_name);
				i++;
			}
		}
		if (closedir(dirp) == -1)
			exit(-1);
	}
	return (maps);
}
