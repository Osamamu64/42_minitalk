/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelshare <oelshare@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 10:31:26 by oelshare          #+#    #+#             */
/*   Updated: 2022/07/03 18:47:27 by oelshare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	x;
	size_t	y;

	x = 0;
	y = n;
	if (n == 0)
		return (0);
	else
	{
		while ((s1[x] != '\0' && s2[x] != '\0')
			&& (s1[x] == s2[x] && x < y - 1))
		{
				x++;
		}
		return (((unsigned char)s1[x]) - ((unsigned char)s2[x]));
	}
}

/*
#include <stdio.h>
#include <string.h>
int main()
{
    char s1[20] = "test\200";
    char s2[20] = "test\0";
  
    int comp = ft_strncmp(s1, s2, 6);
  
   	if (comp == 0) 
	{
        printf("s1 = s2\n");
	}
    else if (comp > 0)
        printf("s1 > s2\n");
    else
        printf("s1 < s2\n");
  
    printf("result: %d", comp);
	printf("\nSecond: %d", strncmp("test\200", "test\0", 6));
    return 0;
}*/