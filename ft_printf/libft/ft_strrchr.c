/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelshare <oelshare@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 14:04:31 by oelshare          #+#    #+#             */
/*   Updated: 2022/09/17 19:29:20 by oelshare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		x;
	char	*s2;

	x = 0;
	s2 = 0;
	while (s[x] != '\0')
	{
		if (s[x] == (char)c)
		{
			s2 = (char *)(s + x);
		}
		x++;
	}
	while (s[x] != '\0')
	{
		x--;
	}
	if (s2)
		return (s2);
	else if (c == '\0')
		return ((char *)(s + x));
	return (NULL);
}

/*
#include <stdio.h>
#include <string.h>
int	main(void)
{
	char	x[] = "bonjourno";
	int	ch = 'o';

	printf("Mine: %s \n", ft_strrchr(x, ch));
	printf("Original: %s \n", strrchr(x, ch));
}*/