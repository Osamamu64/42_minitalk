/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelshare <oelshare@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 11:27:18 by oelshare          #+#    #+#             */
/*   Updated: 2022/07/05 23:27:05 by oelshare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	x;

	x = 0;
	while (x < n)
	{
		*((char *)s + x) = 0;
		x++;
	}
}

/*int	main()
{
	char str[20] = "My name is Osama";

	printf("\nBefore: %s\n", str);
	ft_bzero(str + 10, 8);
	printf ("After:  %s ", str);
	return (0);
}*/