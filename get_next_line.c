/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erintala <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 13:39:59 by erintala          #+#    #+#             */
/*   Updated: 2017/05/08 13:40:11 by erintala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(const int fd, char **line)
{
	static char	buf[BUFF_SIZE + 1];
	char		*temp;
	char		*ptr;
	int			ret;

	if (!line)
		return (-1); 
	if (contains_newline(buf) == 1)
	{
		*line = get_line(buf);
		trim_buf(buf);
		return (1);
	}
	ptr = ft_strnew(BUFF_SIZE);
	temp = ft_strjoin(buf, ptr);
	ft_strclr(buf);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		temp = ft_strjoin(temp, buf);
		if ((contains_newline(buf)) == 1)
		{
			*line = get_line(temp);
			trim_buf(buf);
			return (1);
		}
	}
	if (ret == 0 && *temp)
	{
		*line = temp;
		ft_strclr(buf);
		return (1);
	}
	return (ret);
}

void	trim_buf(char *buf)
{
	int size;

	size = 0;
	while (buf[size] != '\n')
		size++;
	buf = ft_strncpy(buf, &buf[size + 1], BUFF_SIZE);
}

char	*get_line(char *buf)
{
	int		size;
	char	*line;

	size = 0;
	while (buf[size] != '\n')
		size++;
	line = ft_strsub(buf, 0, size);
	return (line);
}

int		contains_newline(char *buf)
{
	char *nl;

	nl = ft_strchr(buf, '\n');
	if (nl == NULL)
		return (0);
	if (*nl == '\n')
		return (1);
	return (0);
}
