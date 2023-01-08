/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelshare <oelshare@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 16:32:18 by oelshare          #+#    #+#             */
/*   Updated: 2022/07/06 01:26:59 by oelshare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	else
		return (n);
}

static void	ft_strrev(char *str)
{
	size_t	size;
	size_t	x;
	char	y;

	size = ft_strlen(str);
	x = 0;
	while (x < size / 2)
	{
		y = str[x];
		str[x] = str[size - x - 1];
		str[size - x - 1] = y;
		x++;
	}
}

char	*ft_itoa(int n)
{
	char	*str;
	int		ngtv;
	size_t	size;
	size_t	x;

	ngtv = (n < 0);
	x = 0;
	str = ft_calloc(11 + ngtv, sizeof(*str));
	if (!str)
		return (NULL);
	if (n == 0)
		str[x] = '0';
	size = 0;
	while (n != '\0')
	{
		str[size] = '0' + ft_abs(n % 10);
		n = (n / 10);
		size++;
	}
	if (ngtv)
		str[size] = '-';
	ft_strrev(str);
	return (str);
}

/*
#include <stdio.h>

int main(void)
{
	int x = 998855;
	
	printf("Result: %s", ft_itoa(x));
}*/
