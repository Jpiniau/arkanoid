/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmonrose <kmonrose@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/23 17:31:27 by kmonrose          #+#    #+#             */
/*   Updated: 2015/12/14 22:50:41 by kmonrose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		ft_count_str(char const *str, char c)
{
	int		count;
	int		btrouve;

	btrouve = 0;
	count = 0;
	while (*str)
	{
		if (*str != c && btrouve == 0)
		{
			btrouve = 1;
			count++;
		}
		else if (*str == c && btrouve == 1)
			btrouve = 0;
		str++;
	}
	return (count);
}

static int		ft_strlen_c(char const *str, int c)
{
	int		i;

	i = 0;
	while (str[i] && str[i] != (char)c)
		i++;
	return (i);
}

static char		*ft_fill_case(char const *str, int size)
{
	int		i;
	char	*copy;

	i = 0;
	copy = (char*)malloc(sizeof(char) * size + 1);
	while (i < size)
	{
		copy[i] = str[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

static int		ft_search_end_str(char const *str, char c)
{
	while (*str && *str == c)
		str++;
	if (*str == 0)
		return (1);
	else
		return (0);
}

char			**ft_strsplit(char const *s, char c)
{
	int		count;
	int		i;
	char	**tab;

	i = 0;
	if (NULL != s)
	{
		count = ft_count_str(s, c);
		if ((tab = (char**)malloc(sizeof(char*) * (count + 1))) != NULL)
		{
			while (*s && !ft_search_end_str(s, c))
			{
				while (*s && *s == c)
					s++;
				tab[i] = ft_fill_case(s, ft_strlen_c(s, c));
				i++;
				while (*s && *s != c)
					s++;
			}
			tab[i] = NULL;
			return (tab);
		}
	}
	return (NULL);
}
