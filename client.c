/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleslie- <rleslie-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 10:02:02 by rleslie-          #+#    #+#             */
/*   Updated: 2023/02/14 18:35:32 by rleslie-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	error(char *msg)
{
	printf("%s\n", msg);
    fflush(stdout);
	exit(0); 
}

int check_digit(char *str)
{
	int i;

	i = 0;
	while(str[i])
	{
		if(ft_isdigit(str[i]))
			i++;
		else
			return (1);
	}
	return (0);
}

void    send_char(pid_t pid, char *message)
{
    int i;
    int shift_bits;
          
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
            usleep(1000);
            shift_bits++;                  
        }
        i++;
    }
    
}

int	main(int argc, char **argv)
{
	pid_t pid;
	
	if (argc != 3)
		error("Wrong numbers of arguments..");
	if (check_digit(argv[1]) || ft_strlen(argv[1]) > 7)
		error("Error PID..");
	pid = ft_atoi(argv[1]);
	send_char(pid, argv[2]);
    send_char(pid, "\n");
	return (0);
}
