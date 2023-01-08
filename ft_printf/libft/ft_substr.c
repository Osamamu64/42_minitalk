/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelshare <oelshare@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 17:33:29 by oelshare          #+#    #+#             */
/*   Updated: 2022/07/06 00:25:16 by oelshare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	x;
	size_t	y;
	char	*sub;

	x = 0;
	y = 0;
	if (s == NULL)
		return (NULL);
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	if (ft_strlen(s) < start + len)
		len = ft_strlen(s) - start;
	sub = (char *)malloc(sizeof(*s) * (len + 1));
	if (!sub)
		return (NULL);
	while (s[x] != '\0')
	{
		if (x >= start && y < len)
		{
			sub[y++] = s[x];
		}
		x++;
	}
	sub[y] = '\0';
	return (sub);
}

/*
int main(void)
{
	char src[] = "Kobe Is the Goat, and he will be for ever\n";

    char *dst = ft_substr(src, 0, 16);
 
    printf("%s", dst);
}*/