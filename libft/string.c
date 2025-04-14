/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oukadir <oukadir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 14:57:06 by oukadir           #+#    #+#             */
/*   Updated: 2025/04/14 20:26:47 by oukadir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i] && i < n)
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			break ;
		i++;
	}
	if (i == n)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

size_t	ft_strlen(const char *c)
{
	size_t	len;

	len = 0;
	while (c[len])
	{
		len++;
	}
	return (len);
}

char	*ft_strdup(const char *str)
{
	int		i;
	int		len;
	char	*c;

	i = 0;
	len = 0;
	while (str[len])
		len++;
	c = (char *)malloc((len + 1) * sizeof(char));
	if (c == NULL)
		return (NULL);
	while (i < len)
	{
		c[i] = str[i];
		i++;
	}
	c[i] = '\0';
	return (c);
}

int ft_strlen2(char **str)
{
	int i;
	i = 0;

	while(str[i])
		i++;
	return(i);
}