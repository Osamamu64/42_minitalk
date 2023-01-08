/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelshare <oelshare@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 21:12:29 by oelshare          #+#    #+#             */
/*   Updated: 2023/01/01 19:33:03 by oelshare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int				ft_printf(const char *format, ...);
int				ft_pointer(unsigned long long ptr);
int				ft_hex(unsigned int nbr, const char format);
int				ft_unsign(unsigned int n);
int				ft_str(char *str);
int				ft_nbr(int x);
int				ft_percent(void);
int				ft_len(unsigned int n);
int				hex_length(unsigned int nbr);
int				ft_converter(va_list args, const char format);
int				ft_putchar(char c);
int				ptr_length(unsigned long long nbr);

char			*ft_unsign_itoa(unsigned int n);

void			place_ptr(unsigned long long nbr);
void			place_hex(unsigned int nbr, const char format);

#endif