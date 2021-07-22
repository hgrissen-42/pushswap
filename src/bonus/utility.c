/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 20:27:39 by hgrissen          #+#    #+#             */
/*   Updated: 2021/07/22 20:53:01 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 == *s2)
	{
		if (*s1 == 0)
			return (0);
		++s1;
		++s2;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

char	*ft_strjoin(char *s, char c)
{
	 int	i;
	char	*str;

	i = 0;
	while (s[i])
		i++;
	str = (char *)malloc(i + 2);
	if (!str)
		ft_error();
	i = 0;
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = c;
	str[i + 1] = '\0';
	return (str);
}

int	get_next_line(char **line)
{
	 int	flag;
	char	buffer;
	char	*tmp;

	*line = (char *)malloc(1);
	if (!line)
		ft_error();
	*line[0] = '\0';
	flag = true;
	while (flag > 0)
	{
		flag = read(0, &buffer, 1);
		if (buffer == '\n')
			break ;
		tmp = ft_strjoin(*line, buffer);
		free(*line);
		*line = tmp;
	}
	return (flag);
}
