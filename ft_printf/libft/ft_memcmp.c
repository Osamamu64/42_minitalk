/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelshare <oelshare@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 17:22:02 by oelshare          #+#    #+#             */
/*   Updated: 2022/07/03 18:43:40 by oelshare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	x;

	x = 0;
	while (x < n)
	{
		if (*(unsigned char *)(s1 + x) != *(unsigned char *)(s2 + x))
			return (*(unsigned char *)(s1 + x) - *(unsigned char *)(s2 + x));
		x++;
	}
	return (0);
}

/*
int main()
{
	char	s1[] = "OSAMA";
	char	s2[] = "osama";
	int	count = 5;
	
	int x = ft_memcmp(s1, s2, count);

	if(x > 0) {
      printf("s2 < s1");
   } else if(x < 0) {
      printf("s1 < s2");
   } else {
      printf("s1 == s2");
   }
}*/