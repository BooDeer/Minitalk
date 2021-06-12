/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudhir <hboudhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 00:58:10 by b00d33r           #+#    #+#             */
/*   Updated: 2021/06/12 18:56:47 by hboudhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"


void	send_char(char ascii, int power, int pid)
{
	if (power > 0)
		send_char(ascii / 2, power - 1, pid);
	if ((ascii % 2) == 1)
	{
		if (kill(pid, SIGUSR1) == -1)
		{
			ft_putstr("Error sending the signal\n");
			exit(0);
		}
	}
	else
	{
		if (kill(pid, SIGUSR2) == -1)
		{
			ft_putstr("Error sending the signal\n");
			exit(0);
		}
	}
	usleep(100);
}

int		send_string(int pid, char *str)
{
	int		i;

	i = -1;
	while (str[++i] != '\0')
		send_char(str[i], 7, pid);
	return (0);
}
int		main(int ac, char **av)
{
	if (ac != 3)
	{
		write(1, "Wrong number of arguments!\n", 27);
		return (0);
	}
	send_string(ft_atoi(av[1]), av[2]);
	//while (69)
	//	pause();
	return (0);
}