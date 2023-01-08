/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelshare <oelshare@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 18:24:49 by oelshare          #+#    #+#             */
/*   Updated: 2022/07/06 00:51:14 by oelshare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*out;
	size_t	x;
	size_t	len;

	len = ft_strlen(s);
	if (s == NULL || f == NULL)
		return (NULL);
	out = (char *)malloc(sizeof(char) * (len + 1));
	if (out == NULL)
		return (NULL);
	x = 0;
	while (s[x] != '\0')
	{
		out[x] = (*f)(x, s[x]);
		x++;
	}
	out[x] = '\0';
	return (out);
}
