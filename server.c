/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleslie- <rleslie-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 09:54:20 by rleslie-          #+#    #+#             */
/*   Updated: 2023/02/14 18:36:07 by rleslie-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char g_char = 0;

void print_char(int signal)
{
    static int  i = 0;
    
    if (signal == SIGUSR1)
        g_char += (1 << i);
    if (i == 7)
    {
        write(1, &g_char, 1);
        g_char = 0;
        i = 0;
        return ;
    }
    i++;
}

int	main()
{
	int	pid;

	pid = getpid();    
	signal(SIGUSR1, print_char);
    signal(SIGUSR2, print_char);
	printf("PID = %d\n", pid);
	while(1)
		pause();
}

