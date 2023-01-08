/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelshare <oelshare@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 12:42:40 by oelshare          #+#    #+#             */
/*   Updated: 2022/07/02 17:08:24 by oelshare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		x;

	x = 0;
	while (s[x])
	{
		if (s[x] == (char)c)
		{
			return ((char *)(s + x));
		}
		x++;
	}
	if (c == '\0')
		return ((char *)(s + x));
	return (NULL);
}

/*
#include <stdio.h>
#include <string.h>
int	main(void)
{
	char	x[] = "bonjour";
	int	ch = '\0';

	printf("Mine: %s \n", ft_strchr(x, ch));
	printf("Original: %s \n", strchr("bonjour", '\0'));
}*/