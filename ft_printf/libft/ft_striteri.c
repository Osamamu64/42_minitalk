/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelshare <oelshare@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 18:52:33 by oelshare          #+#    #+#             */
/*   Updated: 2022/07/06 01:02:03 by oelshare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	x;
	size_t	len;

	x = 0;
	len = ft_strlen(s);
	if (s == NULL || f == NULL)
		return ;
	while (len > x)
	{
		(*f)(x, &s[x]);
		++x;
	}
}
