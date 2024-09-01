/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hurabe <hurabe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 16:36:12 by hurabe            #+#    #+#             */
/*   Updated: 2024/09/01 18:55:22 by hurabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "libft/libft.h"

bool	g_acknowledgement = false;

static void	ft_error(int error)
{
	if (error == INPUT_ERROR)
		ft_printf("'./client [PID] [string]'");
	if (error == PID_ERROR)
		ft_printf("PID is wrong, Please check again PID!");
	if (error == KILL_ERROR)
		ft_printf("kill command error");
	exit(EXIT_FAILURE);
}

static void	send_signal(int s_pid, char *s)
{
	int		i;
	char	c;

	while (*s)
	{
		i = 8;
		c = *s++;
		while (i--)
		{
			if (c >> i & 1)
			{
				if (kill(s_pid, SIGUSR2) == -1)
					ft_error(KILL_ERROR);
			}
			else
			{
				if (kill(s_pid, SIGUSR1) == -1)
					ft_error(KILL_ERROR);
			}
			g_acknowledgement = false;
			usleep(3500);
		}
	}
	ft_printf("client finish!\n");
	exit(0);
}

int	main(int argc, char **argv)
{
	int		i_pid;

	if (argc != 3)
		ft_error(INPUT_ERROR);
	i_pid = ft_atoi(argv[1]);
	send_signal(i_pid, argv[2]);
	send_signal(i_pid, "\0");
	return (0);
}
