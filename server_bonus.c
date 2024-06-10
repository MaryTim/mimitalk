/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbudkevi <mbudkevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:48:22 by mbudkevi          #+#    #+#             */
/*   Updated: 2024/05/16 12:03:00 by mbudkevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include "ft_printf/ft_printf.h"
#include "libft/libft.h"

void	bits_to_string(int bit, int pid)
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
		if (c == 0 && pid)
			kill(pid, SIGUSR1);
		write(1, &c, 1);
		i = 0;
		c = 0;
	}
}

void	handle_signals(int signum, siginfo_t *info, void *context)
{
	(void) context;
	if (signum == SIGUSR1)
		bits_to_string(1, info->si_pid);
	else if (signum == SIGUSR2)
		bits_to_string(0, info->si_pid);
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("PID from the server is: %i\n", getpid());
	sa.sa_sigaction = &handle_signals;
	sa.sa_flags = SA_RESTART | SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{
	}
	return (0);
}
