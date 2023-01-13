/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelshare <oelshare@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:25:41 by oelshare          #+#    #+#             */
/*   Updated: 2023/01/11 18:07:51 by oelshare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minitalk_bonus.h"

static void	to_binary(int sign, siginfo_t *info, void *ptr)
{
	static char	bit;
	static char	total_bits;

	(void) ptr;
	if (sign == SIGUSR1)
		bit |= 1;
	if (sign == SIGUSR2)
		bit |= 0;
	total_bits++;
	if (total_bits == 8)
	{
		ft_printf(YELLOW "%c", bit);
		total_bits = 0;
		bit = 0;
		kill(info->si_pid, SIGUSR1);
	}
	bit <<= 1;
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;

	if (argc != 1)
	{
		ft_printf(RED "PID not showing up", argv[0]);
		exit(0);
	}
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = to_binary;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_printf(GREEN "\n\t\t 🤖 Welcome to your server 🤖 \n\n" C_OFF, getpid());
	ft_printf(GREEN "Your server PID: %u \n\nYour Message: " C_OFF, getpid());
	while (1)
		pause();
	return (0);
}
