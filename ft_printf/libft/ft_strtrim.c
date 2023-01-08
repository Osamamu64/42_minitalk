/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelshare <oelshare@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 17:26:24 by oelshare          #+#    #+#             */
/*   Updated: 2022/07/06 01:42:41 by oelshare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	set_check(char s, char const *set)
{
	unsigned int	x;

	x = 0;
	while (set[x] != '\0')
	{
		if (set[x] == s)
			return (1);
		x++;
	}	
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trim;
	size_t	x;
	size_t	first;
	size_t	last;

	x = 0;
	first = 0;
	last = ft_strlen(s1);
	if (s1 == 0 || set == 0)
		return (NULL);
	while (s1[first] != '\0' && set_check(s1[first], set))
		first++;
	while (first < last && set_check(s1[last - 1], set))
		last--;
	trim = malloc(sizeof(char) * (last - first + 1));
	if (!trim)
		return (NULL);
	while (first < last)
	{
		trim[x] = s1[first];
		x++;
		first++;
	}
	trim[x] = '\0';
	return (trim);
}

/*
int	main(void)
{
	char s[] = "Kobe is the Goat Goat";
	char set[] = "Goat";

    char *output = ft_strtrim(s, set);
 
    printf(" Before: %s\n After: %s", s,  output);
}*/