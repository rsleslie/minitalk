/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 17:02:52 by fsuomins          #+#    #+#             */
/*   Updated: 2023/02/15 15:22:57 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/minitalk_bonus.h"

char	g_char = 0;

void	print_char(int signal, siginfo_t *siginfo, void *context)
{
	static int	i = 0;

	(void)context;
	if (signal == SIGUSR1)
		g_char += (1 << i);
	if (i == 7)
	{
		write(1, &g_char, 1);
		g_char = 0;
		i = 0;
		kill(siginfo->si_pid, SIGUSR2);
		return ;
	}
	i++;
	kill(siginfo->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	s_sa;
	sigset_t			sigset;
	int					pid;

	sigemptyset(&sigset);
	sigaddset(&sigset, SIGUSR1);
	sigaddset(&sigset, SIGUSR2);
	s_sa.sa_handler = NULL;
	s_sa.sa_mask = sigset;
	s_sa.sa_flags = SA_SIGINFO;
	s_sa.sa_sigaction = print_char;
	sigaction(SIGUSR1, &s_sa, NULL);
	sigaction(SIGUSR2, &s_sa, NULL);
	pid = getpid();
	ft_printf("PID = %d\n", pid);
	while (1)
		pause();
}
