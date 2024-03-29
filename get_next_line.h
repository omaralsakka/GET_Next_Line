/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelfa <oabdelfa@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 16:44:32 by oabdelfa          #+#    #+#             */
/*   Updated: 2022/01/11 10:39:03 by oabdelfa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H
# define FD_SIZE 4096
# define NL '\n'
# define BUFF_SIZE 10000
# include "libft/libft.h"
# include <fcntl.h>

int	get_next_line(const int fd, char **line);

#endif
