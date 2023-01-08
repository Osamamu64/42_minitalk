/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelshare <oelshare@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 19:25:43 by oelshare          #+#    #+#             */
/*   Updated: 2022/07/06 01:25:43 by oelshare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	x;
	int	neg;
	int	output;

	x = 0;
	neg = 1;
	output = 0;
	while (str[x] == '\n' || str[x] == '\t' || str[x] == '\v'
		|| str[x] == '\f' || str[x] == '\r' || str[x] == ' ')
		x++;
	if (str[x] == '-' || str[x] == '+')
	{
		if (str[x] == '-')
			neg = -1;
		x++;
	}
	while (str[x] >= '0' && str[x] <= '9')
	{
		output = (output * 10) + (str[x] - '0');
		if (output > (long)INT_MAX || output < (long)INT_MIN)
			return (-1);
		x++;
	}
	return (output * neg);
}

/*
int	main(void)
{
	printf("%d\n", ft_atoi("-123456789"));
	printf("%d\n", atoi("-123456789"));
	return (0);
}*/