/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleslie- <rleslie-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 19:52:07 by fsuomins          #+#    #+#             */
/*   Updated: 2023/02/15 17:28:44 by rleslie-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H


# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <sys/types.h>
# include "../../libft/libft.h"


void	print_char(int sig, siginfo_t *siginfo, void *context);

#endif
