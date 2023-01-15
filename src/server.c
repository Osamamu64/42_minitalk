/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelshare <oelshare@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:01:35 by oelshare          #+#    #+#             */
/*   Updated: 2023/01/15 15:14:58 by oelshare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minitalk.h"
#include <stdio.h>

static void	to_binary(int sign, siginfo_t *info, void *ptr)
{
	static char	bit;
	static char	total_bits;

	(void) ptr;
	(void) info;
	if (sign == SIGUSR1)
		bit |= 1;
	if (sign == SIGUSR2)
		bit |= 0;
	total_bits++;
	if (total_bits == 8)
	{
		ft_putchar(bit);
		total_bits = 0;
		bit = 0;
	}
	bit <<= 1;
}

int	main(int argc, char **argv)
{
	struct sigaction	s_action;

	if (argc != 1)
	{
		ft_printf(RED "./server accepts only 1 Argument", argv[0]);
		exit(0);
	}
	s_action.sa_flags = SA_SIGINFO;
	s_action.sa_sigaction = to_binary;
	sigaction(SIGUSR1, &s_action, NULL);
	sigaction(SIGUSR2, &s_action, NULL);
	ft_printf(GREEN "\n\t\t 🤖 Welcome to your server 🤖 \n\n" C_OFF);
	ft_printf(GREEN "Your server PID: %u \n\nYour Message: " C_OFF, getpid());
	while (1)
		pause();
	return (0);
}
