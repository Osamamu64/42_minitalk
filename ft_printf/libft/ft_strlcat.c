/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelshare <oelshare@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 14:51:37 by oelshare          #+#    #+#             */
/*   Updated: 2022/07/03 18:33:35 by oelshare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	x;
	size_t	dst_l;
	size_t	src_l;

	dst_l = ft_strlen(dst);
	src_l = ft_strlen(src);
	x = 0;
	if (dst_l > dstsize)
		return (src_l + dstsize);
	else if (dstsize == 0)
		return (src_l + dstsize);
	while (src[x] != '\0' && dst_l + x + 1 < dstsize)
	{
			dst[dst_l + x] = src[x];
			x++;
	}
	dst[dst_l + x] = '\0';
	return (dst_l + src_l);
}

/*
#include <string.h>
#include <stdio.h>
int	main(void)
{
	int x;
	int z;
	char src[] = "lorem";
    char *dst;
	dst[11] = 'a';
	int size = 15;
	
	x = ft_strlcat(dst,"lorem",size);
    printf("----------------MINE---------------- \nsize: %d\n",x);
	
    char *dst1;
	dst1[11] = 'a';
    int size1 = 15;
	z = strlcat(dst1,"lorem",size);
    printf("----------------FUNCTION---------------- \nsize: %d\n",z);
}*/