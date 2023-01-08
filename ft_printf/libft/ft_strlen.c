/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelshare <oelshare@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 12:18:16 by oelshare          #+#    #+#             */
/*   Updated: 2022/07/03 18:32:03 by oelshare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t		x;

	x = 0;
	while (s[x] != '\0')
	{
		x++;
	}
	return (x);
}
/*
int	main(void)
{
	char	x[6];

	x[6] = "OSAMA";
	printf("%d \n", ft_strlen(x));
}*/