/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelshare <oelshare@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 17:52:50 by oelshare          #+#    #+#             */
/*   Updated: 2022/07/03 18:51:00 by oelshare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int	x;
	int	y;

	x = 0;
	if (!(dst && src))
		return (NULL);
	if (dst > src)
	{
		x = (int)len - 1;
		while (x >= 0)
		{
			*(unsigned char *)(dst + x) = *(unsigned char *)(src + x);
			x--;
		}
	}
	else
	{
		y = (int)len;
		while (x < y)
		{
			*(char *)(dst + x) = *(char *)(src + x);
			x++;
		}
	}
	return (dst);
}

/*int	main(void)
{
	char dst[24] = "Lakers will win or lose";
	char * x = dst + 19;
	char * src = dst + 12;
	printf( "Before, dst: \"%s\"\n", dst );
  	ft_memmove( x, src, 4 );
  	printf( "After, dst: \"%s\"\n", dst );
}*/