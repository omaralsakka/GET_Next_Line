/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelfa <oabdelfa@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 18:17:42 by oabdelfa          #+#    #+#             */
/*   Updated: 2022/01/11 11:24:29 by oabdelfa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char *ft_assignl(char *str, char **line, size_t i)
{
	char *tmp;
	
	*line = ft_strsub(str, 0, i);
	tmp = ft_strdup(&(str[i + 1]));
	ft_free(str, ft_strlen(str));
	return (tmp);
}

static int	ft_readl(char **str, char **line)
{
	size_t	i;

	i = ft_strlenc(*str, NL);
	if ((*str)[i] == NL)
	{
		*str = ft_assignl(*str, line, i);
		if (!(*str)[0])
			ft_strdel(str);
	}
	else
	{
		*line = ft_strdup(*str);
		ft_strdel(str);
	}
	return (1);
}

static int	ft_res(char **str, char **line, int txt, int fd)
{
	if (txt < 0)
		return (-1);
	else if (txt == 0 && !str[fd])
		return (0);
	return (ft_readl(&str[fd], line));
}

int	get_next_line(const int fd, char **line)
{
	int			txt;
	char		*tmp;
	char		buff[BUFF_SIZE + 1];
	static char	*str[FD_SIZE];

	if (fd < 0 || !line || fd > FD_SIZE)
		return (-1);
	txt = read(fd, buff, BUFF_SIZE);
	while (txt > 0)
	{
		buff[txt] = '\0';
		if (!str[fd])
			str[fd] = ft_strdup(buff);
		else
		{
			tmp = ft_strjoin(str[fd], buff);
			ft_free(str[fd], ft_strlen(str[fd]));
			str[fd] = tmp;
		}
		if (ft_strchr(str[fd], NL))
			break ;
		txt = read(fd, buff, BUFF_SIZE);
	}
	return (ft_res(str, line, txt, fd));
}
