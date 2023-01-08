/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelshare <oelshare@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 17:07:22 by oelshare          #+#    #+#             */
/*   Updated: 2022/07/03 18:47:43 by oelshare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	x;
	size_t	y;

	x = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[x] != '\0')
	{
		y = 0;
		while (haystack[x + y] == needle[y] && (x + y) < len)
		{
			if (haystack[x + y] == '\0' && needle[y] == '\0')
				return ((char *)&haystack[x]);
			y++;
		}
		if (needle[y] == '\0')
			return ((char *)haystack + x);
		x++;
	}
	return (0);
}

/*
int main()
{
	const char	*largestring = "Kobe will always be the goat";
    const char	*smallstring = "the";
	char	*ptr;

    ptr = ft_strnstr(largestring, smallstring, 29);
    printf("Result: %s \n", ptr);
       
    ptr = ft_strnstr(largestring, smallstring, 11);
    printf("Result: %s \n", ptr);
       
    ptr = ft_strnstr(largestring, smallstring, 12);
    printf("Result: %s", ptr);
         
}*/