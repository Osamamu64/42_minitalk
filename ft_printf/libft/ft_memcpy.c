/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelshare <oelshare@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 16:52:50 by oelshare          #+#    #+#             */
/*   Updated: 2022/08/04 21:09:52 by oelshare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	x;

	if (!dst)
		return (NULL);
	x = 0;
	while (x < n)
	{
		*(char *)(dst + x) = *(char *)(src + x);
		x++;
	}
	return (dst);
}

/*
int main ()
{
  char x[] = "Osama"; 
  char y[] = "Goat"; 
 
  printf("x before memcpy: %s ", x);
  ft_memcpy (x, y, 5);
  printf("\nx After memcpy: %s ", x);
}*/
