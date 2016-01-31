/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmonrose <kmonrose@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/03 14:00:10 by kmonrose          #+#    #+#             */
/*   Updated: 2015/12/05 06:34:58 by kmonrose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	ft_init_cmpt(int *tab, int *eof, char *buf)
{
	C1 = 0;
	C2 = 0;
	C3 = 0;
	FLAG = 0;
	RET = 0;
	if (*eof)
	{
		*eof = 0;
		while (C1 < BUFF_SIZE + 1)
		{
			buf[C1] = 0;
			C1++;
		}
	}
	C1 = 0;
}

static void	ft_test_last_buf(char **line, int *tab, char *buf)
{
	void	*f;

	*line = ft_strdup("");
	if (buf[0] != 0)
	{
		f = *line;
		*line = ft_strjoin(*line, buf);
		free(f);
		while (C1 < (int)ft_strlen(buf))
		{
			if (LINE == '\n' && FLAG == 0)
			{
				LINE = '\0';
				FLAG = 1;
			}
			else if (FLAG == 1)
			{
				buf[C2] = LINE;
				C2++;
			}
			C1++;
		}
	}
}

static void	ft_search_endline(int *tab, char *buf, char **line)
{
	while (C3 + C1 < C3 + RET)
	{
		if (LINE == '\n' && FLAG == 0)
		{
			LINE = '\0';
			FLAG = 1;
		}
		else if (FLAG == 1)
		{
			buf[C2] = LINE;
			C2++;
		}
		C1++;
	}
}

static int	ft_compute_buf(int *tab, char *buf, char **line)
{
	void	*f;

	buf[RET] = '\0';
	f = *line;
	*line = ft_strjoin(*line, buf);
	free(f);
	C1 = 0;
	C2 = 0;
	ft_search_endline(tab, buf, line);
	if (FLAG)
	{
		buf[C2] = '\0';
		return (1);
	}
	C3 += RET;
	return (0);
}

int			get_next_line(int const fd, char **line)
{
	static char		buf[BUFF_SIZE + 1] = {0};
	static int		eof = 0;
	int				tab[5];

	if (BUFF_SIZE < 0)
		return (-1);
	ft_init_cmpt(tab, &eof, buf);
	ft_test_last_buf(line, tab, buf);
	if (FLAG)
	{
		buf[C2] = '\0';
		return (1);
	}
	C3 = C1;
	while ((RET = read(fd, buf, BUFF_SIZE)) > 0)
	{
		if (ft_compute_buf(tab, buf, line))
			return (1);
	}
	if (ft_strlen(*line) > 0 && !eof)
	{
		eof = 1;
		return (1);
	}
	return (RET);
}
