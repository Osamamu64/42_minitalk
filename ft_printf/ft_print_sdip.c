/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_sdip.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelshare <oelshare@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 23:08:05 by oelshare          #+#    #+#             */
/*   Updated: 2023/01/01 20:46:09 by oelshare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	ft_str(char *str)
{
	int	x;

	x = 0;
	if (str == NULL)
		return (write(1, "(null)", 6));
	while (str[x] != '\0')
	{
		write(1, &str[x], 1);
		x++;
	}
	return (x);
}

int	ft_nbr(int x)
{
	int		len;
	char	*nbr;

	len = 0;
	nbr = ft_itoa(x);
	len = ft_str(nbr);
	free(nbr);
	return (len);
}

int	ft_percent(void)
{
	return (write(1, "%", 1));
}
