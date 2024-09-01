/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hurabe <hurabe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 16:36:12 by hurabe            #+#    #+#             */
/*   Updated: 2024/09/01 16:09:07 by hurabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "libft/libft.h"

bool	g_acknowledgement = false;

//static void	handle_check(int pid)
//{
//	int	i;

//	i = 8;
//	//while (i--)
//	//{
//	//	kill(pid, SIGUSR1);
//	//	usleep(100);
//	//}
//	//printf("%d\n",sig);
//	//if (sig == SIGUSR1)
//	//	g_acknowledgement = true;
//	//ft_printf("Client, Finish!");
//}

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

//static void	send_signal(int s_pid, char c)
static void	send_signal(int s_pid, char *s)
{
	//int	sig;
	//int	i;
	int		i;
	char	c;

	while (*s)
	{
		i = 8;
		c = *s++;
		while (i--)
		{
			//if (c & (1 << i))
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
			//	sig = SIGUSR1;
			//g_acknowledgement = false;
			//if (kill(s_pid, sig) == -1)
			//	ft_error(KILL_ERROR);
			//while (g_acknowledgement == false)
			//{
			//	printf("test");
			//	usleep(50);
			//}
			//while (kill(s_pid, sig) == -1)
			g_acknowledgement = false;
			usleep(3500);
		}
		//if (*s == '\0')
	}
	ft_printf("client finish!\n");
	exit(0);
}

//static int	check_pid(char *c_pid)
//{
//	int	i;
//	int	len;
//	int	i_pid;

//	len = ft_strlen(c_pid);
//	i = 0;
//	while (i < len)
//	{
//		if (!ft_isdigit(c_pid[i]))
//			ft_error(PID_ERROR);
//		i++;
//	}
//	i_pid = ft_atoi(c_pid);
//	if (i_pid <= 1)
//		ft_error(PID_ERROR);
//	return (i_pid);
//}

int	main(int argc, char **argv)
{
	int		i_pid;

	if (argc != 3)
		ft_error(INPUT_ERROR);
	i_pid = ft_atoi(argv[1]);
	//signal(SIGUSR1, handle_check);
	//signal(SIGUSR2, handle_check);
	send_signal(i_pid, argv[2]);
	send_signal(i_pid, "\0");
	//while (1)
	//pause();
	return (0);
}
