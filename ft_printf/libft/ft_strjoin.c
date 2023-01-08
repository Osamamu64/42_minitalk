/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelshare <oelshare@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 18:51:57 by oelshare          #+#    #+#             */
/*   Updated: 2022/07/06 01:42:17 by oelshare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*join;
	size_t			x;
	size_t			y;

	x = 0;
	y = 0;
	if (s1 == 0 || s2 == 0)
		return (NULL);
	join = (char *)malloc(sizeof(*s1) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!join)
		return (NULL);
	while (s1[x] != '\0')
	{
		join[y++] = s1[x++];
	}
	x = 0;
	while (s2[x] != '\0')
	{
		join[y++] = s2[x++];
	}
	join[y] = '\0';
	return (join);
}

/*
int	main(void)
{
	char s1[] = "Kobe is";
	char s2[] = " the GOAT\n";

    char *output = ft_strjoin(s1, s2);
 
    printf("%s", output);
}*/