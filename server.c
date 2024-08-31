/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hurabe <hurabe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 16:36:20 by hurabe            #+#    #+#             */
/*   Updated: 2024/08/31 20:40:41 by hurabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	signal_handler(int sig, siginfo_t *info, void *context)
{
	static int		c_pid;
	static char		c;
	static int		i;

	(void)context;
	if (!c_pid)
		c_pid = info->si_pid;
	if (sig == SIGUSR2)
		c |= (1 << i);
	i++;
	if (i == 8)
	{
		i = 0;
		if (c == '\0')
		{
			if (sig == SIGUSR1)
				kill(c_pid, SIGUSR1);
			else
				kill(c_pid, SIGUSR2);
			c_pid = 0;
			write(1, "\n", 1);
			return ;
		}
		write(1, &c, 1);
		c = 0;
	}
	return ;
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("PID: %d\n", getpid());

	sigemptyset(&sa.sa_mask);
	sa.sa_sigaction = signal_handler;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
