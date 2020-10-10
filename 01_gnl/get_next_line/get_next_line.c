/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 20:59:49 by hopark            #+#    #+#             */
/*   Updated: 2020/10/10 21:51:48 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

6436#include "get_next_line.h"

static int			read_error(char **remain)
{
	if (*remain != NULL)
	{
		free(*remain);
		*remain = 0;
	}
	return (-1);
}

static int			make_line(char **line, char **remain, char *line_ptr)
{
	char		*temp;
	size_t		remain_s;
	size_t		line_s;

	remain_s = ft_strlen(*remain);
	line_s = (line_ptr == 0) ? remain_s : line_ptr - *remain;
	if (!(temp = (char *)malloc(sizeof(char) * (line_s + 1))))
		return (read_error(remain));
	ft_strncpy(temp, *remain, line_s);
	temp[line_s] = 0;
	*line = temp;
	if (line_ptr == 0)
	{
		free(remain);
		*remain = 0;
		return (1);
	}
	if (!(temp = (char *)malloc(sizeof(char) * (remain_s - (line_s + 1) + 1))))
		return (read_error(remain));
	temp[remain_s - (line_s + 1)] = 0;
	free(*remain);
	*remain = temp;
	return (1);
}

static int			read_eof(char **line, char **remain)
{
	char		*temp;

	if (remain == 0)
	{
		if (!(temp = (char *)malloc(1 * sizeof(char))))
			return (read_error(remain));
		temp[0] = 0;
		*line = temp;
	}
	else
		make_line(line, remain, 0);
	return (0);
}

int					get_next_line(int fd, char **line)
{
	static char		*remain[OPEN_MAX];
	char			buf[BUFFER_SIZE + 1];
	char			*line_ptr;
	size_t			read_size;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0 || !line)
		return (-1);
	while ((line_ptr = ft_strchr(remain[fd], '\n')) == 0)
	{
		read_size = read(fd, buf, BUFFER_SIZE);
		if (read_size < 0)
			break ;
		buf[read_size] = 0;
		if ((remain[fd] = ft_strncat_free(remain[fd], buf, read_size)) == 0)
			return (read_error(&remain[fd]));
	}
	if (line_ptr == 0)
	{
		if (read_size == 0)
			return (read_eof(line, &remain[fd]));
		else if (read_size < 0)
			return (read_error(&remain[fd]));
	}
	return (make_line(line, &remain[fd], line_ptr));
}
