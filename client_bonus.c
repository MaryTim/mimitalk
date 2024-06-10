/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbudkevi <mbudkevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:47:15 by mbudkevi          #+#    #+#             */
/*   Updated: 2024/05/16 12:02:47 by mbudkevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	j = 7;
	while (j >= 0)
	{
		kill(pid, SIGUSR2);
		usleep(500);
		j--;
	}
}

void	signal_handler(int signum)
{
	if (signum == SIGUSR1)
		ft_printf("\nServer has received the message!");
}

int	main(int argc, char **argv)
{
	int					server_pid;
	char				*text;
	struct sigaction	sa;

	sa.sa_handler = &signal_handler;
	sa.sa_flags = SA_RESTART;
	sigaction(SIGUSR1, &sa, NULL);
	if (argc == 3)
	{
		server_pid = ft_atoi(argv[1]);
		if (!server_pid)
		{
			ft_printf("Something is wrong with server's PID");
			return (0);
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
