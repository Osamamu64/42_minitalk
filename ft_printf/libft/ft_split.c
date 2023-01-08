/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelshare <oelshare@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 20:38:32 by oelshare          #+#    #+#             */
/*   Updated: 2022/07/05 20:30:50 by oelshare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	allocater(char **tab, char const *s, char sp)
{
	char	**tabx;
	int		x;
	int		y;
	int		z;

	x = 0;
	z = 0;
	tabx = tab;
	while (s[x] != '\0')
	{
		while (s[x] == sp)
			x++;
		y = x;
		while (s[x] != '\0' && s[x] != sp)
			x++;
		if (x > y)
		{
			tabx[z] = ft_substr(s + y, 0, x - y);
			z++;
		}
	}
	tabx[z] = 0;
}

static int	counter(char const *s, char c)
{
	int	count;
	int	x;

	count = 0;
	x = 0;
	while (s[x] != '\0')
	{
		while (s[x] == c)
			x++;
		if (s[x] != '\0')
			count++;
		while (s[x] != '\0' && s[x] != c)
			x++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**split;

	if (!s)
		return (NULL);
	split = (char **)malloc(sizeof(char *) * (counter(s, c) + 1));
	if (!split)
		return (NULL);
	allocater(split, s, c);
	return (split);
}
