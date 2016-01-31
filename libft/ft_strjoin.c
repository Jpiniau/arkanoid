/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmonrose <kmonrose@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/23 11:17:32 by kmonrose          #+#    #+#             */
/*   Updated: 2015/12/14 21:57:21 by kmonrose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char	*ft_copy_join(const char *s1, const char *s2, char *copy)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s1[i] != 0)
	{
		copy[i] = s1[i];
		i++;
	}
	while (s2[j] != 0)
	{
		copy[i] = s2[j];
		i++;
		j++;
	}
	copy[i] = '\0';
	return (copy);
}

char		*ft_strjoin(const char *s1, const char *s2)
{
	char	*scat;
	char	*cmp_null;
	int		len;

	len = 0;
	cmp_null = NULL;
	if (cmp_null != s1 && cmp_null != s2)
	{
		len = ft_strlen(s1) + ft_strlen(s2) + 1;
		if ((scat = (char*)malloc(sizeof(char) * len)) != NULL)
		{
			scat = ft_copy_join(s1, s2, scat);
			return (scat);
		}
		else
			return (NULL);
	}
	return ((char*)s1);
}
