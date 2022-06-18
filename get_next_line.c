/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruland <anruland@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 17:05:01 by anruland         #+#    #+#             */
/*   Updated: 2022/03/22 10:17:14 by anruland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_join(char *main_buf, char *buf)
{
	char	*tmp;

	tmp = ft_strjoin(main_buf, buf);
	free(main_buf);
	return (tmp);
}

char	*ft_read_file(int fd, char *main_buf)
{
	int		exit;
	char	*buf;

	exit = 1;
	if (!main_buf)
		main_buf = (char *)ft_calloc(1, sizeof(*main_buf));
	buf = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(*buf));
	while (exit > 0)
	{
		if (ft_strchr(buf, '\n'))
			exit = 0;
		else
		{
			exit = read(fd, buf, BUFFER_SIZE);
			buf[exit] = '\0';
			main_buf = ft_join(main_buf, buf);
		}
	}
	free(buf);
	return (main_buf);
}

char	*ft_prepare_line(const char *main_buf)
{
	char	*line;
	int		i;

	i = 0;
	if (!main_buf[0])
		return (NULL);
	while (main_buf[i] && main_buf[i] != '\n')
		i++;
	line = (char *)ft_calloc((i + 2), sizeof(*line));
	i = 0;
	while (main_buf[i] && main_buf[i] != '\n')
	{
		line[i] = main_buf[i];
		i++;
	}
	if (main_buf[i] == '\n')
	{
		line[i] = '\n';
	}
	return (line);
}

char	*ft_prepare_next(char *main_buf, unsigned int i, unsigned int j)
{
	while (main_buf[i] && main_buf[i] != '\n')
		i++;
	if (!main_buf[i])
	{
		free(main_buf);
		return (NULL);
	}
	if (main_buf[i] == '\n')
	{
		i++;
		while (main_buf[j])
		{
			if (main_buf[i])
			{
				main_buf[j] = main_buf[i];
				j++;
			}
			else
				main_buf[j] = '\0';
			i++;
		}
	}
	return (main_buf);
}

char	*get_next_line(int fd)
{
	static char	*main_buf;
	char		*ret;

	if (fd < 0 || read(fd, 0, 0) < 0 || BUFFER_SIZE == 0)
		return (NULL);
	main_buf = ft_read_file(fd, main_buf);
	if (!main_buf)
		return (NULL);
	ret = ft_prepare_line(main_buf);
	main_buf = ft_prepare_next(main_buf, 0, 0);
	return (ret);
}
