/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erintala <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 13:39:59 by erintala          #+#    #+#             */
/*   Updated: 2017/05/05 13:40:11 by erintala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft/libft.h"


# define BUFF_SIZE 1

int		get_next_line(const int fd, char **line);
void	trim_buf(char *buf);
char	*get_line(char *buf);
int		contains_newline(char *buf);

#endif
