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
	char		*holder;
	int			ret;

	if (!line)
		return (-1); 
	if (contains_newline(buf) == 1)
	{
		*line = get_line(buf, 0);
		trim_buf(buf);
		return (1);
	}
	temp = ft_strnew(BUFF_SIZE);
	holder = ft_strjoin(buf, temp);
	free(temp);
	temp = holder;
	ft_strclr(buf);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		holder = ft_strjoin(temp, buf);
		free(temp);
		temp = holder;
		if ((contains_newline(buf)) == 1)
		{
			*line = get_line(temp, 1);
			trim_buf(buf);
			return (1);
		}
		ft_strclr(buf);
	}
	if (ret == 0 && *temp != 0 && *buf == 0)
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
	while (buf[size] != '\n' )
		size++;
	buf = ft_strncpy(buf, &buf[size + 1], BUFF_SIZE);
}

char	*get_line(char *buf, int flag)
{
	int		size;
	char	*line;
	char	*holder;

	size = 0;
	while (buf[size] != '\n')
		size++;
	holder = ft_strsub(buf, 0, size);
	if (flag == 1)
		free(buf);
	line = holder;
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
