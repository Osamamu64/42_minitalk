/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelshare <oelshare@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:01:28 by oelshare          #+#    #+#             */
/*   Updated: 2023/01/08 15:08:20 by oelshare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void args_check(int pid, char *str)
{
    if (pid < PID_MIN || pid > PID_MAX)
    {
        ft_printf(RED "ERROR: The required PID range is from: %d to %d "
            C_OFF, PID_MIN, PID_MAX);
        exit(0);
    }
    if (!str)
    {
        ft_printf(RED "ERROR: You must have a string" C_OFF);
        exit(0);
    }
}

static void str_converter(int pid, char *str)
{
    int index;
    int len_shift;

    index = 0;
    while(str[index])
    {
        len_shift = 7;
        while(len_shift >= 0)
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


int main(int argc, char **argv)
{
    int pid;
    
    if (argc != 3)
    {
        ft_printf(RED " 3 ARGUMENTS REQUIRED!!" C_OFF, argv[0]);
        exit(0);
    }
    pid = ft_atoi(argv[1]);
    args_check(pid, argv[2]);
    str_converter(pid, argv[2]);
    return (0);
}
