/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelshare <oelshare@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 15:36:58 by oelshare          #+#    #+#             */
/*   Updated: 2022/07/03 21:05:35 by oelshare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	x;
	size_t	y;

	x = 0;
	y = dstsize;
	if (y > 0)
	{
		while (src[x] != '\0' && x < (y - 1))
		{
			dst[x] = src[x];
			x++;
		}
		dst[x] = 0;
	}
	while (src[x])
		x++;
	return (x);
}

/*
int	main(void)
{
	char src[] = "Lakers will win";
    char dst[16];
	int size = 12;
    int x;
	
 x = ft_strlcpy(dst,src,size);

    printf("Before: %s \nAfter: %s \nsize: %d\n", src, dst, x);
}*/
