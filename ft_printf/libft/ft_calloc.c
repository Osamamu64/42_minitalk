/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelshare <oelshare@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 20:07:58 by oelshare          #+#    #+#             */
/*   Updated: 2022/07/05 23:42:33 by oelshare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if (size != 0 && (count > SIZE_MAX / size))
		return (NULL);
	ptr = (void *)malloc(count * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, (count * size));
	return (ptr);
}
/*
#include <stdio.h>
#include <stdlib.h>
int	main(void)
{
    int *ptr;
    int x;
	
    x = '0';
    printf("Elements: %d\n", x);
 
    ptr = ft_calloc(0, sizeof(int));
 
    if (ptr == NULL) {
        printf("Error\n");
    }
    else {
        printf("Allocated Sucessfully: %d\n", ptr[x]);
    }
 
}*/