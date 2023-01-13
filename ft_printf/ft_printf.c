/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelshare <oelshare@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 20:22:54 by oelshare          #+#    #+#             */
/*   Updated: 2023/01/11 19:51:55 by oelshare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_converter(va_list args, const char format)
{
	int	len;

	len = 0;
	if (format == 'c')
		len += ft_putchar(va_arg(args, int));
	else if (format == 's')
		len += ft_str(va_arg(args, char *));
	else if (format == 'p')
		len += ft_pointer(va_arg(args, unsigned long long));
	else if (format == 'd' || format == 'i')
		len += ft_nbr(va_arg(args, int));
	else if (format == 'u')
		len += ft_unsign(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		len += ft_hex(va_arg(args, unsigned int), format);
	else if (format == '%')
		len += ft_percent();
	return (len);
}

int	ft_printf(const char *format, ...)
{
	int		x;
	va_list	args;
	int		len;

	x = 0;
	len = 0;
	va_start(args, format);
	while (format[x] != '\0')
	{
		if (format[x] == '%')
		{
			len += ft_converter(args, format[x + 1]);
			x++;
		}
		else
			len += ft_putchar(format[x]);
		x++;
	}
	va_end(args);
	return (len);
}
