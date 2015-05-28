/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboeuf <eboeuf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/09 14:37:14 by eboeuf            #+#    #+#             */
/*   Updated: 2014/02/09 19:59:51 by eboeuf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <signal.h>
#include <unistd.h>
#include <stdio.h>

void	addchar(int c)
{
	static char		*s = NULL;
	static int		i = 0;

	if (s == NULL)
		s = (char *)malloc(sizeof(char) * 16000);
	if (c == 4)
	{
		i = 0;
		ft_putstr(s);
		ft_putchar('\n');
		free(s);
		s = NULL;
	}
	else
	{
		s[i] = c;
		i++;
	}
}

int		bintodec(const char *bin)
{
	int		i;
	int		j;

	i = 0;
	j = 8;
	while ((j--) && ((*bin == '0') || (*bin == '1')))
	{
		i <<= 1;
		if (*bin == '1')
			i++;
		bin++;
	}
	return (i);
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

void	ft_handler(int sign)
{
	static char	*s = NULL;
	static int	i = 0;

	if (s == NULL)
	{
		s = (char *)malloc(sizeof(char) * 9);
		initialize(s);
	}
	if (sign == SIGUSR1)
		s[i] = '0';
	else if (sign == SIGUSR2)
		s[i] = '1';
		i++;
	if (i == 8)
	{
		addchar(bintodec(s));
		i = 0;
		free(s);
		s = NULL;
	}
}

int		main(void)
{
	ft_putnbr(getpid());
	ft_putchar('\n');
	signal(SIGUSR1, &ft_handler);
	signal(SIGUSR2, &ft_handler);
	while (1)
		pause();
	return (0);
}
