/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbudkevi <mbudkevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 13:55:01 by mbudkevi          #+#    #+#             */
/*   Updated: 2024/05/15 13:39:45 by mbudkevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include "ft_printf/ft_printf.h"
#include "libft/libft.h"

void	bits_to_string(int bit)
{
	static int	i = 0;
	static char	c = 0;

	if (i < 8)
	{
		c |= bit << (7 - i);
		i++;
	}
	if (i == 8)
	{
		write(1, &c, 1);
		i = 0;
		c = 0;
	}
}

void	signal_handler(int signum)
{
	if (signum == SIGUSR1)
		bits_to_string(1);
	else if (signum == SIGUSR2)
		bits_to_string(0);
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("PID from the server is: %i\n", getpid());
	sa.sa_handler = &signal_handler;
	sa.sa_flags = SA_RESTART;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{
	}
	return (0);
}
