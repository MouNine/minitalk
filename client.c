/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboeuf <eboeuf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/09 16:54:15 by eboeuf            #+#    #+#             */
/*   Updated: 2014/02/12 17:07:40 by eboeuf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void	dectobin(int n, char *s, int i)
{
	if (n)
	{
		if (n > 1)
			dectobin(n / 2, s, i - 1);
		s[i] = '0' + n % 2;
	}
}

void	sendsign(char *s, pid_t pid)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '1')
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
			usleep(125);
		i++;
	}
}

void	initialize(char *s)
{
	int		i;

	i = 0;
	while (i < 8)
	{
		s[i] = '0';
		i++;
	}
	s[i] = 0;
}

int		main(int ac, char **av)
{
	pid_t	pid;
	int		i;
	char	*s;

	i = 0;
	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		s = (char *)malloc(sizeof(char) * 9);
		while (av[2][i])
		{
			initialize(s);
			dectobin(av[2][i], s, 7);
			sendsign(s, pid);
			i++;
		}
		usleep(125);
		sendsign("00000100", pid);
	}
	free(s);
	return (0);
}
