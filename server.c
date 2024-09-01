/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hurabe <hurabe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 16:36:20 by hurabe            #+#    #+#             */
/*   Updated: 2024/09/01 16:04:41 by hurabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	signal_handler(int sig, siginfo_t *info, void *context)
{
	static int				i = 0;
	static pid_t			client_pid = 0;
	static unsigned char	c = 0;

	(void)context;
	//(void)info;
	if (!client_pid)
		client_pid = info->si_pid;
	c |= (sig == SIGUSR2);
	if (++i == 8)
	{
		i = 0;
		if (!c)
		{
			kill(client_pid, SIGUSR2);
			client_pid = 0;
			return ;
		}
		ft_putchar_fd(c, 1);
		c = 0;
		////kill(client_pid, SIGUSR1);
	}
	else
		c <<= 1;
}
//static void	signal_handler(int sig, siginfo_t *info, void *context)
//{
//	static int		c_pid = 0;
//	static unsigned char	c = 0;
//	static int		i = 0;

//	(void)context;
//	if (c_pid == 0)
//		c_pid = info->si_pid;
//	if (sig == SIGUSR2)
//		c |= (1 << i);
//	i++;
//	if (i == 8)
//	{
//		write(1, &c, 1);
//		i = 0;
//		c = 0;
//		if (c == '\0')
//			c_pid = 0;
//	}
//	kill(c_pid, SIGUSR1);
//}

//static void	signal_handler(int sig, siginfo_t *info, void *context)
//{
//	static int		c_pid;
//	static char		c;
//	static int		i;

//	(void)context;
//	if (!c_pid)
//		c_pid = info->si_pid;
//	if (sig == SIGUSR2)
//		c |= (1 << i);
//	i++;
//		kill(c_pid, SIGUSR1);
//	if (i == 8)
//	{
//		write(1, &c, 1);
//		i = 0;
//		if (c == '\0')
//		{
//			//kill(c_pid, SIGUSR1);
//			c_pid = 0;
//		}
//		c = 0;
//		//write(1, "\n", 1);
//	}
//	return ;
//}

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
