/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lendir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 12:13:02 by jpiniau           #+#    #+#             */
/*   Updated: 2016/01/31 12:19:36 by jpiniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_lendir(DIR* dir)
{
	int				i;
	struct dirent*	dr;

	i = 0;
	while ((dr = readdir(dir)) != NULL)
	{
		if (ft_strcmp(dr->d_name, ".") != 0 && ft_strcmp(dr->d_name, "..") != 0)
			i++;
	}
	return i;
}

