/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelshare <oelshare@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 12:28:53 by oelshare          #+#    #+#             */
/*   Updated: 2022/07/03 18:43:26 by oelshare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	x;

	if (!s)
		return (NULL);
	x = 0;
	while (x < n)
	{
		if (*(unsigned char *)(s + x) == (unsigned char)c)
			return ((void *)(s + x));
		x++;
	}
	return (NULL);
}

/*
int main()
{
    char s[] = "Osama is the goat";
    char n= 't';
	int count = 17;
   	if (ft_memchr(s, n, count))
		printf("The charchter is found at %d", n);
	else 
		printf("Not found");
}*/
