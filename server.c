/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudhir <hboudhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 00:58:08 by b00d33r           #+#    #+#             */
/*   Updated: 2021/06/12 18:55:06 by hboudhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"


void	send_char(int signum)
{
	static int ascii = 0;
	static int powah = 0;

	if (signum == SIGUSR1)
		ascii += 1 << (7 - powah);
	powah++;
	if (powah == 8)
	{
		ft_putchar(ascii);
		ascii = 0;
		powah = 0;
	}
		
}
int		main(int ac, char **av)
{
	if (ac != 1)
	{
		write(1, "Error! Wrong number of arguments.\n", 33);
		return (0);
	}
	write(1, "Server's PID: ", 14);
	ft_putnbr(getpid());
	write(1, "\n", 1);
	(void)ac;
	(void)av;

	signal(SIGUSR1, send_char);
	signal(SIGUSR2, send_char);
	while (69)
		pause();
	return (0);
}