/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr_fd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oukadir <oukadir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 14:57:01 by oukadir           #+#    #+#             */
/*   Updated: 2025/04/14 14:57:54 by oukadir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	special_cases(int n, int fd)
{
	int	min_int;

	min_int = -2147483648;
	if (n == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	if (n == min_int)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
}

static void	write_number(int n, int fd)
{
	int		i;
	char	s[11];

	i = 0;
	while (n > 0)
	{
		s[i] = n % 10 + 48;
		n = n / 10;
		i++;
	}
	i--;
	while (i >= 0)
	{
		write(fd, &s[i], 1);
		i--;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == 0 || n == -2147483648)
	{
		special_cases(n, fd);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = n * (-1);
	}
	write_number(n, fd);
}

void	ft_putstr_fd(char *s, int fd)
{
	size_t	i;

	i = 0;
	if (s == NULL)
		return ;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}
