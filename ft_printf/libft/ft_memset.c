/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelshare <oelshare@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 10:28:43 by oelshare          #+#    #+#             */
/*   Updated: 2022/07/03 18:44:53 by oelshare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	x;

	x = 0;
	while (x < len)
	{
		*((char *)b + x) = c;
		x++;
	}
	return (b);
}

/*int	main()
{
	char str[50] = "I wanna go a vacation";

	printf("\nBefore: %s\n", str);
	ft_memset(str + 13, '.', 8);
	printf ("After:  %s ", str);
	return (0);
}*/