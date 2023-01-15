/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelshare <oelshare@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:25:44 by oelshare          #+#    #+#             */
/*   Updated: 2023/01/15 16:24:41 by oelshare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minitalk_bonus.h"

int	g_word_count;

static	void	args_check(int pid, char *str)
{
	if (pid < PID_MIN || pid > PID_MAX)
	{
		ft_printf(RED "ERROR: The required PID range is from: %d to %d "
			C_OFF, PID_MIN, PID_MAX);
		exit(0);
	}
	else if (kill(pid, 0) == -1)
	{
		ft_printf(RED "ERROR: Wrong PID number \n" C_OFF);
		exit(0);
	}
	else if (!*str)
	{
		ft_printf(RED "ERROR: You must have a string" C_OFF);
		exit(0);
	}
}

static void	str_converter(int pid, char *str)
{
	int	index;
	int	len_shift;

	index = 0;
	while (str[index])
	{
		len_shift = 7;
		while (len_shift >= 0)
		{
			if ((str[index] & (1 << len_shift)) > 0)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			len_shift--;
			usleep(100);
		}
		index++;
	}
}

static void	acknowledger(int sign, siginfo_t *info, void *ptr)
{
	static int	sent_str;

	(void) ptr;
	(void) info;
	if (sign == SIGUSR1)
		sent_str++;
	if (sent_str == g_word_count)
	{
		ft_printf(YELLOW
			"A message have been recived ✅ \n" C_OFF, sent_str);
		exit(1);
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	s_action;
	int					pid;

	if (argc != 3)
	{
		ft_printf(RED " %s Need 3 Arguments!!" C_OFF, argv[0]);
		exit(0);
	}
	s_action.sa_flags = SA_SIGINFO;
	s_action.sa_sigaction = acknowledger;
	sigaction(SIGUSR1, &s_action, NULL);
	pid = ft_atoi(argv[1]);
	args_check(pid, argv[2]);
	g_word_count = ft_strlen(argv[2]);
	str_converter(pid, argv[2]);
	while (1)
		pause();
	return (0);
}
