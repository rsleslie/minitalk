/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 13:32:55 by fsuomins          #+#    #+#             */
/*   Updated: 2023/02/15 15:23:06 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/minitalk_bonus.h"

int	g_bit;

void	received(int sig)
{
	if (sig == SIGUSR1)
		g_bit++;
	else if (sig == SIGUSR2)
	{
		ft_printf("Send letter\n");
		g_bit++;
	}
	else
	{
		ft_printf("\tError: Signal is invalid.\n");
		exit(22);
	}
}

void	error(char *msg)
{
	ft_printf("%s\n", msg);
	exit(0);
}

int	check_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
			i++;
		else
			return (1);
	}
	return (0);
}

void	send_char(pid_t pid, char *message)
{
	int	i;
	int	shift_bits;

	i = 0;
	while (message[i])
	{
		shift_bits = 0;
		while (shift_bits < 8)
		{
			if ((message[i] >> shift_bits) & 0b00000001)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(5000);
			shift_bits++;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;

	signal(SIGUSR1, received);
	signal(SIGUSR2, received);
	if (argc != 3)
		error("Wrong numbers of arguments..");
	if (check_digit(argv[1]) || ft_strlen(argv[1]) > 7)
		error("Error PID..");
	pid = ft_atoi(argv[1]);
	send_char(pid, argv[2]);
	send_char(pid, "\n");
	return (0);
}
