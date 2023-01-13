/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelshare <oelshare@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:01:28 by oelshare          #+#    #+#             */
/*   Updated: 2023/01/13 23:05:44 by oelshare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minitalk.h"

static	void	args_check(int pid, char *str)
{
	if (pid < PID_MIN || pid > PID_MAX)
	{
		ft_printf(RED "ERROR: The required PID range is from: %d to %d \n"
			C_OFF, PID_MIN, PID_MAX);
		exit(0);
	}
	if (!*str)
	{
		ft_printf(RED "ERROR: You must have a string \n" C_OFF);
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
			usleep(50);
		}
		index++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	pid = ft_atoi(argv[1]);
	if (argc == 3)
	{
		if (kill(pid, 1) == -1 || pid != 0)
		{
			ft_printf(RED "ERROR: Wrong PID number \n" C_OFF, argv[0]);
			exit(0);
		}
		else
		{
			args_check(pid, argv[2]);
			str_converter(pid, argv[2]);
		}
	}
	else
	{
		ft_printf(RED " %s Need 3 Arguments!! \n" C_OFF, argv[0]);
		exit(0);
	}
	/*if ((kill(pid, -1)) == -1 || pid == 0)
	{
		ft_printf(RED "ERROR: Wrong PID number \n" C_OFF, argv[0]);
		exit(0);
		pid = 0;
	}*/
	return (0);
}
