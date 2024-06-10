/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbudkevi <mbudkevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 13:54:54 by mbudkevi          #+#    #+#             */
/*   Updated: 2024/05/16 11:52:05 by mbudkevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>
#include "libft/libft.h"
#include "ft_printf/ft_printf.h"

void	send_data(int pid, char *text)
{
	int	i;
	int	j;

	i = 0;
	while (text[i])
	{
		j = 7;
		while (j >= 0)
		{
			if (((text[i] >> j) & 1) == 1)
				kill(pid, SIGUSR1);
			else if (((text[i] >> j) & 1) == 0)
				kill(pid, SIGUSR2);
			usleep(500);
			j--;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int		server_pid;
	char	*text;

	if (argc == 3)
	{
		server_pid = ft_atoi(argv[1]);
		if (!server_pid)
		{
			ft_printf("Something is wrong with server's PID");
			return (1);
		}
		text = argv[2];
		send_data(server_pid, text);
	}
	else
	{
		ft_printf("Something is wrong with arguments! ");
		ft_printf("Make sure you enter both PID and message");
	}
	return (0);
}
