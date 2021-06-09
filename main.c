/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: b00d33r <b00d33r@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 00:46:55 by b00d33r           #+#    #+#             */
/*   Updated: 2021/06/08 01:31:38 by b00d33r          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int ar, char **av)
{
	int	pid = fork();
	
	if (pid == -1)
		return (1);
	
	if (!pid)
	{
		while (1)
		{
			printf("Hello world!\n");
			usleep(500000);
		}
	}
	else
	{
		sleep(2);
		wait(NULL);
		kill(pid, SIGKILL);
		
	}
}